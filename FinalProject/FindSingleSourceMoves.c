
#include <General.h>
#include <FindSingleSourceMoves.h>

SingleSourceMovesTree *FindSingleSourceMoves(Board board, checkersPos *src)
{
    //Declare variables
    SingleSourceMovesTree tree;
    SingleSourceMovesTreeNode* curr;
    char row=src->row;
    char col=src->col;

    //Check if there is player tool
    if(board[row][col] != NULL)
    {
        if(board[row][col] == PLAYER_A)
        {
            //check the right side
            if(board[row+1][col+1] == PLAYER_A)

            //check the left side
        }
        if((board[src->row][src->col] == PLAYER_B)
        {

        }
    }
    else
        return NULL;
}

SingleSourceMovesTreeNode* FindSingleSourceMovesForPlayerA(Board board, char row, char col)
{
    SingleSourceMovesTreeNode* tr;

    if(board[row][col] == PLAYER_A)
    {
        //Check right square
        if(board[row+1][col+1] == PLAYER_A)
            tr->next_move[1]=NULL;
        else if(board[row+1][col+1] == PLAYER_B)
            //send to recursion
        else if(board[row+1][col+1] == SYMBOL)
            //send to recursion


    }
    else if(board[row][col] == PLAYER_B)
    {
        if(board[row+1][col+1] == PLAYER_A)
            //return null
        else if(board[row+1][col+1] == PLAYER_B)
            //return null
        else if(board[row+1][col+1] == SYMBOL)
        //send to recursion

    }
    else if(board[row][col] == SYMBOL)
    {
        if(board[row+1][col+1] == PLAYER_A)
            //return just the node
        else if(board[row+1][col+1] == PLAYER_B)
            //send to recursion
        else if(board[row+1][col+1] == SYMBOL)
        //send to recursion
    }

    tr->board=board;
    *(tr->pos).col=col;
    *(tr->pos).row=row;
    tr->total_captures_so_far=0;

}