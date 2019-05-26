#include <General.h>
#include <Tree.h>
#include <FindSingleSourceMoves.h>
#include <stdlib.h>

SingleSourceMovesTree *FindSingleSourceMoves(Board board, checkersPos *src)
{
    //Declare variables
    SingleSourceMovesTree* tree;
    SingleSourceMovesTreeNode* curr;
    int row;
    int col;
    row=src->row - '0';
    col=src->col - '0';
    unsigned char currSymbol=board[row][col];
    Player currPlayer;
    Player otherPlayer;
    unsigned short totalCapturesSoFar=0;

    //Check if there is a player tool in the current square
    if(currSymbol == TOP_PLAYER || currSymbol == BOTTOM_PLAYER)
    {
        tree=(SingleSourceMovesTree*)malloc(sizeof(SingleSourceMovesTree));

        if(currSymbol==TOP_PLAYER)
        {
            currPlayer=TOP_PLAYER;
            //otherPlayer=BOTTOM_PLAYER;
        }
        if(currSymbol==BOTTOM_PLAYER)
        {
            currPlayer=BOTTOM_PLAYER;
            //otherPlayer=TOP_PLAYER;
        }
        if(currPlayer==TOP_PLAYER)
        {
            curr=checkMoveOfTopPlayerRec(board,row,col,totalCapturesSoFar);
        }
        else if(currPlayer==BOTTOM_PLAYER)
        {
            curr=checkMoveOfBottomPlayerRec(board,row,col,totalCapturesSoFar);
        }
        tree->source=curr;
        return tree;
    }
    else
        return NULL;
}

//Check if the player tool reached to the top of the board
BOOL checkIfReachToTopOfBoard(int row)
{
    return(row - 1 < 0);
}

//Check if the player tool reached to the end of the board
BOOL checkIfReachToEndOfBoard(int row)
{
    return(row + 1 >= BOARD_SIZE);
}

//Check if reached to the right end of the board
BOOL checkIfReachToRightEndOfBoard(int col)
{
    return(col + 1 >= BOARD_SIZE);
}

//Check if reached to the left end of the board
BOOL checkIfReachToLeftEndOfBoard(int col)
{
    return(col - 1 < 0);
}

//Check if the player can move
SingleSourceMovesTreeNode* checkMoveOfTopPlayerRec(Board board,int row,int col, unsigned short totalCapturesSoFar)
{
    SingleSourceMovesTreeNode* curr=NULL;
    //Check if the player tool can move left or right to the next square
        if(board[row][col] == TOP_PLAYER || board[row][col] == SYMBOL)
        {
            curr=createNewTreeNode(board,row,col);
            curr->total_captures_so_far=totalCapturesSoFar;
        }
        if(board[row][col] == TOP_PLAYER)
        {
            //right
            if (!checkIfReachToRightEndOfBoard(col) && !checkIfReachToEndOfBoard(row))
            {
                if (board[row + 1][col + 1] == SYMBOL && totalCapturesSoFar == 0)
                {
                    curr->next_move[RIGHT_MOVE_INDEX] = createNewTreeNode(board, row + 1, col + 1);

                }
            }
            //left
            if (!checkIfReachToLeftEndOfBoard(col) && !checkIfReachToEndOfBoard(row))
            {
                if (board[row + 1][col - 1] == SYMBOL && totalCapturesSoFar == 0)
                {
                    curr->next_move[LEFT_MOVE_INDEX] = createNewTreeNode(board, row + 1, col - 1);

                }
            }
        }
        if(board[row][col] == TOP_PLAYER || board[row][col] == SYMBOL)
        {
            //right
            if (!checkIfReachToRightEndOfBoard(col) && !checkIfReachToEndOfBoard(row))
            {
                if(board[row+1][col+1] == BOTTOM_PLAYER)
                {
                    if (!checkIfReachToRightEndOfBoard(col + 1) && !checkIfReachToEndOfBoard(row + 1))
                    {
                        if (board[row + 2][col + 2] == SYMBOL)
                        {
                            curr->next_move[RIGHT_MOVE_INDEX] = checkMoveOfTopPlayerRec(board, row + 2, col + 2, totalCapturesSoFar + 1);
                        }
                    }
                }
            }
            //left
            if (!checkIfReachToLeftEndOfBoard(col) && !checkIfReachToEndOfBoard(row))
            {
                if(board[row+1][col-1] == BOTTOM_PLAYER)
                {
                    if (!checkIfReachToLeftEndOfBoard(col - 1) && !checkIfReachToEndOfBoard(row + 1))
                    {
                        if (board[row + 2][col - 2] == SYMBOL)
                        {
                            curr->next_move[LEFT_MOVE_INDEX] = checkMoveOfTopPlayerRec(board, row + 2, col - 2, totalCapturesSoFar+1);
                        }
                    }
                }
            }
        }
        return curr;
}

//Check if the player can move
SingleSourceMovesTreeNode* checkMoveOfBottomPlayerRec(Board board,int row,int col, unsigned short totalCapturesSoFar)
{
    SingleSourceMovesTreeNode* curr=NULL;
    //Check if the player tool can move left or right to the next square
    if(board[row][col] == BOTTOM_PLAYER || board[row][col] == SYMBOL)
    {
        curr=createNewTreeNode(board,row,col);
        curr->total_captures_so_far=totalCapturesSoFar;
    }
    if(board[row][col] == BOTTOM_PLAYER)
    {
        //right
        if (!checkIfReachToRightEndOfBoard(col) && !checkIfReachToTopOfBoard(row))
        {
            if (board[row - 1][col + 1] == SYMBOL && totalCapturesSoFar == 0)
            {
                curr->next_move[RIGHT_MOVE_INDEX] = createNewTreeNode(board, row - 1, col + 1);

            }
        }
        //left
        if (!checkIfReachToLeftEndOfBoard(col) && !checkIfReachToTopOfBoard(row))
        {
            if (board[row - 1][col - 1] == SYMBOL && totalCapturesSoFar == 0)
            {
                curr->next_move[LEFT_MOVE_INDEX] = createNewTreeNode(board, row - 1, col - 1);

            }
        }
    }
    if(board[row][col] == BOTTOM_PLAYER || board[row][col] == SYMBOL)
    {
        //right
        if (!checkIfReachToRightEndOfBoard(col) && !checkIfReachToTopOfBoard(row))
        {
            if(board[row-1][col+1] == TOP_PLAYER)
            {
                if (!checkIfReachToRightEndOfBoard(col + 1) && !checkIfReachToTopOfBoard(row - 1))
                {
                    if (board[row - 2][col + 2] == SYMBOL)
                    {
                        curr->next_move[RIGHT_MOVE_INDEX] = checkMoveOfBottomPlayerRec(board, row - 2, col + 2, totalCapturesSoFar + 1);
                    }
                }
            }
        }
        //left
        if (!checkIfReachToLeftEndOfBoard(col) && !checkIfReachToTopOfBoard(row))
        {
            if(board[row-1][col-1] == TOP_PLAYER)
            {
                if (!checkIfReachToLeftEndOfBoard(col - 1) && !checkIfReachToTopOfBoard(row - 1))
                {
                    if (board[row - 2][col - 2] == SYMBOL)
                    {
                        curr->next_move[LEFT_MOVE_INDEX] = checkMoveOfBottomPlayerRec(board, row - 2, col - 2, totalCapturesSoFar+1);
                    }
                }
            }
        }
    }
    return curr;
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