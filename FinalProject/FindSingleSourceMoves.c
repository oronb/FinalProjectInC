#include <General.h>
#include <Tree.h>
#include <FindSingleSourceMoves.h>
#include <stdlib.h>

SingleSourceMovesTree *FindSingleSourceMoves(Board board, checkersPos *src)
{
    //Declare variables
    SingleSourceMovesTree* tree;
    SingleSourceMovesTreeNode* curr;
    int row=src->row - '0';
    int col=src->col - '0';
    unsigned char currSymbol=board[row][col];
    Player currPlayer;
    Player otherPlayer;

    //Check if there is a player tool in the current square
    if(currSymbol == TOP_PLAYER || currSymbol == BOTTOM_PLAYER)
    {
        tree=(SingleSourceMovesTree*)malloc(sizeof(SingleSourceMovesTree));

        if(currSymbol==TOP_PLAYER)
        {
            currPlayer=TOP_PLAYER;
            otherPlayer=BOTTOM_PLAYER;
        }
        if(currSymbol==BOTTOM_PLAYER)
        {
            currPlayer=BOTTOM_PLAYER;
            otherPlayer=TOP_PLAYER;
        }
        //Setting the player tool square
        curr=createNewTreeNode(board,row,col);
        //copyBoard(board,curr->board);
        curr->pos->col=col;
        curr->pos->row=row;
        curr->total_captures_so_far=0;

        //Setting the tree move of the player
        if(currSymbol == TOP_PLAYER)
        {
            //Check if reached to the right end of the board
            if(!checkIfReachToRightEndOfBoard(row,col))
                curr->next_move[RIGHT_MOVE_INDEX]=FindSingleSourceMovesRec(board,row+1,col+1,currPlayer,otherPlayer);
            //Check if reached to the left end of the board
            if(!checkIfReachToLeftEndOfBoard(row,col))
                curr->next_move[LEFT_MOVE_INDEX]=FindSingleSourceMovesRec(board,row+1,col-1,currPlayer,otherPlayer);
        }
        else if(currSymbol == BOTTOM_PLAYER)
        {
            //Check if reached to the right top of the board
            if(!checkIfReachToRightEndOfBoard(row,col))
                curr->next_move[RIGHT_MOVE_INDEX]=FindSingleSourceMovesRec(board,row-1,col+1,currPlayer,otherPlayer);
            //Check if reached to the left top of the board
            if(!checkIfReachToLeftEndOfBoard(row,col))
                curr->next_move[LEFT_MOVE_INDEX]=FindSingleSourceMovesRec(board,row-1,col-1,currPlayer,otherPlayer);
        }
        tree->source=curr;
        return tree;
    }
    else
        return NULL;
}

SingleSourceMovesTreeNode* FindSingleSourceMovesRec(Board board, int row, int col,Player currPlayer, Player otherPlayer)
{
    SingleSourceMovesTreeNode* res;
    BOOL canMoveToRight;
    BOOL canMoveToLeft;
    unsigned char currSymbol=board[row][col];
    unsigned short total_captures_so_far=0;

    if(currSymbol == currPlayer)
    {
        res=NULL;
    }
    else if(checkIfPlayerReachedToTheEnd(currPlayer,row,col))
    {
        if(currSymbol==SYMBOL)
            res=createNewTreeNode(board,row,col);
    }
    else
    {
        checkMoveOfPlayer(board,row,col,currPlayer,otherPlayer,currSymbol,&canMoveToLeft,&canMoveToRight);
        if(canMoveToLeft || canMoveToRight || currSymbol == SYMBOL)
        {
            res=createNewTreeNode(board, row, col);
            //copyBoard(board,res->board);
            res->pos->col=col;
            res->pos->row=row;
            res->total_captures_so_far=0;
        }
        if(currPlayer==TOP_PLAYER)
        {
            if (canMoveToRight)
                res->next_move[RIGHT_MOVE_INDEX] = FindSingleSourceMovesRec(board, row + 1, col + 1, currPlayer, otherPlayer);
            if (canMoveToLeft)
                res->next_move[LEFT_MOVE_INDEX] = FindSingleSourceMovesRec(board, row + 1, col - 1, currPlayer, otherPlayer);
            if (!canMoveToRight && !canMoveToLeft && currSymbol != SYMBOL)
                res=NULL;
        }
        else if(currPlayer==BOTTOM_PLAYER)
        {
            if (canMoveToRight)
                res->next_move[RIGHT_MOVE_INDEX] = FindSingleSourceMovesRec(board, row - 1, col + 1, currPlayer, otherPlayer);
            if (canMoveToLeft)
                res->next_move[LEFT_MOVE_INDEX] = FindSingleSourceMovesRec(board, row - 1, col - 1, currPlayer, otherPlayer);
            if (!canMoveToRight && !canMoveToLeft && currSymbol != SYMBOL)
                res=NULL;
        }
    }
    return res;
}

//Check if player reached to the end
BOOL checkIfPlayerReachedToTheEnd(Player currPlayer, int row, int col)
{
    BOOL reachedToTheEnd=FALSE;
    if(currPlayer==TOP_PLAYER)
    {
        reachedToTheEnd=checkIfReachToEndOfBoard(row,col);
    }
    else if(currPlayer==BOTTOM_PLAYER)
    {
        reachedToTheEnd=checkIfReachToTopOfBoard(row,col);
    }
    return reachedToTheEnd;
}

//Check if the player tool reached to the top of the board
BOOL checkIfReachToTopOfBoard(int row,int col)
{
    return(row - 1 < 0 || col - 1 < 0 || col + 1 >= BOARD_SIZE);
}

//Check if the player tool reached to the end of the board
BOOL checkIfReachToEndOfBoard(int row,int col)
{
    return(row + 1 >= BOARD_SIZE || col - 1 < 0 || col + 1 >= BOARD_SIZE);
}

//Check if reached to the right end of the board
BOOL checkIfReachToRightEndOfBoard(int row,int col)
{
    return(col + 1 >= BOARD_SIZE);
}

//Check if reached to the left end of the board
BOOL checkIfReachToLeftEndOfBoard(int row,int col)
{
    return(col - 1 < 0);
}

//Check if the player can move
void checkMoveOfPlayer(Board board,int row,int col,char currPlayer,char otherPlayer,unsigned char currSquareSymbol, BOOL* canMoveLeft,BOOL* canMoveRight)
{
    //Define variables

    //Check if the player tool can move left or right to the next square
    if(currPlayer==TOP_PLAYER)
    {
        //check if can move Right
        if(!checkIfReachToRightEndOfBoard(row,col))
            *canMoveRight=canMoveToNextSquare(board,row+1,col+1,currPlayer,otherPlayer,currSquareSymbol);
        else
            *canMoveRight=FALSE;
        //Check if can move Left
        if(!checkIfReachToLeftEndOfBoard(row,col))
            *canMoveLeft=canMoveToNextSquare(board,row+1,col-1,currPlayer,otherPlayer,currSquareSymbol);
        else
            *canMoveLeft=FALSE;
    }
    else if(currPlayer==BOTTOM_PLAYER)
    {
        if(!checkIfReachToRightEndOfBoard(row,col))
            *canMoveRight=canMoveToNextSquare(board,row-1,col+1,currPlayer,otherPlayer,currSquareSymbol);
        else
            *canMoveRight=FALSE;
        if(!checkIfReachToLeftEndOfBoard(row,col))
            *canMoveLeft=canMoveToNextSquare(board,row-1,col-1,currPlayer,otherPlayer,currSquareSymbol);
        else
            *canMoveLeft=FALSE;
    }
}

//check if the player tool can move to the next square
BOOL canMoveToNextSquare(Board board, int nextRow,int nextCol,Player currPlayer,Player otherPlayer,unsigned char currSquareSymbol)
{
    //Define variable
    BOOL canMove=FALSE;

    //check if the player tool can move from square that contains the player tool
    if(currSquareSymbol==currPlayer)
        canMove=FALSE;

    //check if the player tool can move from square that contains the other player tool
    else if(currSquareSymbol==otherPlayer)
    {
        if(board[nextRow][nextCol]==currPlayer)
            canMove=FALSE;
        if(board[nextRow][nextCol]==otherPlayer)
            canMove=FALSE;
        if(board[nextRow][nextCol]==SYMBOL)
            canMove=TRUE;
    }

    //check if the player tool can move from an empty square
    if(currSquareSymbol==SYMBOL)
    {
        if(board[nextRow][nextCol] == currPlayer)
            canMove = FALSE;
        else if(board[nextRow][nextCol] == otherPlayer)
            canMove = TRUE;
        else if(board[nextRow][nextCol] == SYMBOL)
            canMove = TRUE;
    }
    return canMove;
}

void copyBoard(Board sourceBoard, Board destBoard)
{
    int row=0,col=0;
    for(row=0; row < BOARD_SIZE; row++)
    {
        for(col=0; col < BOARD_SIZE; col++)
            destBoard[row][col]=sourceBoard[row][col];
    }
}