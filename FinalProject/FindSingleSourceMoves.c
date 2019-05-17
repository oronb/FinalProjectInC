
#include <General.h>
#include <Tree.h>
#include <FindSingleSourceMoves.h>

SingleSourceMovesTree *FindSingleSourceMoves(Board board, checkersPos *src)
{
    //Declare variables
    SingleSourceMovesTree* tree;
    SingleSourceMovesTreeNode* curr;
    char row=src->row;
    char col=src->col;
    char currSymbol=board[src->row][src->col];
    Player currPlayer;
    Player otherPlayer;

    //Check if there is a player tool in the current square
    if(currSymbol != NULL)
    {
        tree=(SingleSourceMovesTree*)malloc(sizeof(SingleSourceMovesTree));
        tree->source=curr;

        if(currSymbol==PLAYER_A)
        {
            currPlayer=PLAYER_A;
            otherPlayer=PLAYER_B;
        }
        if(currSymbol==PLAYER_B)
        {
            currPlayer=PLAYER_B;
            otherPlayer=PLAYER_A;
        }
        //Setting the player tool square
        curr=createTreeNode();
        curr->board=board;
        *(curr->pos).col=col;
        *(curr->pos).row=row;
        curr->total_captures_so_far=0;

        //Setting the tree move of the player
        if(currSymbol == PLAYER_A && !checkIfReachToEndOfBoard(row,col))
        {
            //check the right side
            curr->next_move[RIGHT_MOVE_INDEX]=FindSingleSourceMovesForPlayer(board,row+1,col+1,currPlayer,otherPlayer);
            //check left side
            curr->next_move[LEFT_MOVE_INDEX]=FindSingleSourceMovesForPlayer(board,row+1,col-1,currPlayer,otherPlayer);
            //check the left side
        }
        else if((currSymbol == PLAYER_B && !checkIfReachToTopOfBoard(row,col))
        {
            //check the right side
            curr->next_move[RIGHT_MOVE_INDEX]=FindSingleSourceMovesForPlayer(board,row-1,col+1,currPlayer,otherPlayer);
            //check left side
            curr->next_move[LEFT_MOVE_INDEX]=FindSingleSourceMovesForPlayer(board,row-1,col-1,currPlayer,otherPlayer);
            //check the left side
        }
    }
    else
        return NULL;
}

SingleSourceMovesTreeNode* FindSingleSourceMovesRec(Board board, char row, char col,Player currPlayer, Player otherPlayer)
{
    SingleSourceMovesTreeNode* res;
    BOOL canMoveToRight;
    BOOL canMoveToLeft;
    char currSymbol=board[row][col];
    unsigned short total_captures_so_far=0;

    if(currSymbol == currPlayer)
    {
        res=NULL;
    }
    elseif(checkLastSquareOfPlayerTool)
    else if(checkIfPlayerReachedToTheEnd(currPlayer,row,col))
    {
        if(currSymbol==currPlayer)
            res=NULL;
        else if(currSymbol==SYMBOL)
            res=createNewTreeNode();
    }
    else
    {
        checkMoveOfPlayer(row,col,currPlayer,otherPlayer,currSymbol,canMoveToLeft,canMoveToRight);
        if(canMoveToLeft || canMoveToRight || currSymbol == SYMBOL)
        {
            res=createNewTreeNode(board, row, col, total_captures_so_far);
            res->board=board;
            *(res->pos).col=col;
            *(res->pos).row=row;
            res->total_captures_so_far=0;
        }
        if(currPlayer==PLAYER_A)
        {
            if (canMoveToRight)
                res->next_move[LEFT_MOVE_INDEX] = FindSingleSourceMovesForPlayer(board, row + 1, col + 1, currPlayer), otherPlayer;
            else if (canMoveToLeft)
                res->next_move[RIGHT_MOVE_INDEX] = FindSingleSourceMovesForPlayer(board, row + 1, col - 1, currPlayer, otherPlayer);
            else if (currSymbol != SYMBOL)
                res=NULL;
        }
        else if(currPlayer==PLAYER_B)
        {
            if (canMoveToRight)
                res->next_move[LEFT_MOVE_INDEX] = FindSingleSourceMovesForPlayer(board, row - 1, col + 1, currPlayer, otherPlayer);
            if (canMoveToLeft)
                res->next_move[RIGHT_MOVE_INDEX] = FindSingleSourceMovesForPlayer(board, row - 1, col - 1, currPlayer, otherPlayer);
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
    else if(currPlayer==PLAYER_A)
    {
        reachedToTheEnd=checkIfReachToEndOfBoard(row,col);
    }
    else if(currPlayer==PLAYER_B)
    {
        reachedToTheEnd=checkIfReachToTopOfBoard(row,col);
    }
    return reachedToTheEnd;
}

//Check if the player tool reached to the top of the board
BOOL checkIfReachToTopOfBoard(row,col)
{
    return(row + 1 >= BOARD_SIZE || col -1 < 0 || col + 1 >= BOARD_SIZE)
}

//Check if the player tool reached to the end of the board
BOOL checkIfReachToEndOfBoard(row,col)
{
    return(row - 1 <= 0 || col -1 < 0 || col + 1 >= BOARD_SIZE)
}

//Check if the player can move
BOOL checkMoveOfPlayer(Board board,int row,int col,char currPlayer,char otherPlayer,char currSquareSymbol, BOOL* canMoveLeft,BOOL* canMoveRight)
{
    //Define variables
    BOOL canMoveLeft=FALSE;
    BOOL canMoveRight=FALSE;


    //Check if the player tool can move left or right to the next square
    if(currPlayer==PLAYER_A)
    {
        canMoveRight=canMoveToNextSquare(board,row+1,col+1,currPlayer,otherPlayer,currSquareSymbol);
        canMoveLeft=canMoveToNextSquare(board,row-1,col-1,currPlayer,otherPlayer,currSquareSymbol);
    }
    else if(currPlayer==PLAYER_B)
    {
        canMoveRight=canMoveToNextSquare(board,row-1,col+1,currPlayer,otherPlayer,currSquareSymbol);
        canMoveLeft=canMoveToNextSquare(board,row-1,col-1,currPlayer,otherPlayer,currSquareSymbol);
    }
    return BOOL;
}

//check if the player tool can move to the next square
BOOL canMoveToNextSquare(Board board, nextRow,nextCol,currPlayer,otherPlayer,currSquareSymbol)
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
    }
    return canMove;
}