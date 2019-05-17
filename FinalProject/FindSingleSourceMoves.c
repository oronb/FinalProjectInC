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
            currPlayer=TOP_PLAYER;
            otherPlayer=BOTTOM_PLAYER;
        }
        //Setting the player tool square
        curr=createNewTreeNode(board,row,col);
        copyBoard(board,curr->board);
        curr->pos->col=col;
        curr->pos->row=row;
        curr->total_captures_so_far=0;

        //Setting the tree move of the player
        if(currSymbol == TOP_PLAYER && checkIfReachToEndOfBoard(row,col))
        {
            //check the right side
            curr->next_move[RIGHT_MOVE_INDEX]=FindSingleSourceMovesRec(board,row+1,col+1,currPlayer,otherPlayer);
            //check left side
            curr->next_move[LEFT_MOVE_INDEX]=FindSingleSourceMovesRec(board,row+1,col-1,currPlayer,otherPlayer);
            //check the left side
        }
        else if(currSymbol == BOTTOM_PLAYER && checkIfReachToTopOfBoard(row,col))
        {
            //check the right side
            curr->next_move[RIGHT_MOVE_INDEX]=FindSingleSourceMovesRec(board,row-1,col+1,currPlayer,otherPlayer);
            //check left side
            curr->next_move[LEFT_MOVE_INDEX]=FindSingleSourceMovesRec(board,row-1,col-1,currPlayer,otherPlayer);
            //check the left side
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
        if(currSymbol==currPlayer)
            res=NULL;
        else if(currSymbol==SYMBOL)
            res=createNewTreeNode(board,row,col);
    }
    else
    {
        checkMoveOfPlayer(board,row,col,currPlayer,otherPlayer,currSymbol,&canMoveToLeft,&canMoveToRight);
        if(canMoveToLeft || canMoveToRight || currSymbol == SYMBOL)
        {
            res=createNewTreeNode(board, row, col);
            copyBoard(board,res->board);
            res->pos->col=col;
            res->pos->row=row;
            res->total_captures_so_far=0;
        }
        if(currPlayer==TOP_PLAYER)
        {
            if (canMoveToRight)
                res->next_move[LEFT_MOVE_INDEX] = FindSingleSourceMovesRec(board, row + 1, col + 1, currPlayer, otherPlayer);
            else if (canMoveToLeft)
                res->next_move[RIGHT_MOVE_INDEX] = FindSingleSourceMovesRec(board, row + 1, col - 1, currPlayer, otherPlayer);
            else if (currSymbol != SYMBOL)
                res=NULL;
        }
        else if(currPlayer==BOTTOM_PLAYER)
        {
            if (canMoveToRight)
                res->next_move[LEFT_MOVE_INDEX] = FindSingleSourceMovesRec(board, row - 1, col + 1, currPlayer, otherPlayer);
            if (canMoveToLeft)
                res->next_move[RIGHT_MOVE_INDEX] = FindSingleSourceMovesRec(board, row - 1, col - 1, currPlayer, otherPlayer);
            else if (currSymbol != SYMBOL)
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
    return(row + 1 >= BOARD_SIZE || col -1 < 0 || col + 1 >= BOARD_SIZE);
}

//Check if the player tool reached to the end of the board
BOOL checkIfReachToEndOfBoard(int row,int col)
{
    return(row - 1 < 0 || col -1 < 0 || col + 1 >= BOARD_SIZE);
}

//Check if the player can move
void checkMoveOfPlayer(Board board,int row,int col,char currPlayer,char otherPlayer,unsigned char currSquareSymbol, BOOL* canMoveLeft,BOOL* canMoveRight)
{
    //Define variables

    //Check if the player tool can move left or right to the next square
    if(currPlayer==TOP_PLAYER)
    {
        *canMoveRight=canMoveToNextSquare(board,row+1,col+1,currPlayer,otherPlayer,currSquareSymbol);
        *canMoveLeft=canMoveToNextSquare(board,row-1,col-1,currPlayer,otherPlayer,currSquareSymbol);
    }
    else if(currPlayer==BOTTOM_PLAYER)
    {
        *canMoveRight=canMoveToNextSquare(board,row-1,col+1,currPlayer,otherPlayer,currSquareSymbol);
        *canMoveLeft=canMoveToNextSquare(board,row-1,col-1,currPlayer,otherPlayer,currSquareSymbol);
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