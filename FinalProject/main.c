//#define _CRT_SECURE_NO_WARNINGS
//Maissa
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <createBoard.h>
#include <printBoard.h>
#include <General.h>
#include <TestingFindAllPossiblePlayerMoves.h>
#include <Tree.h>
#include <StoreBoard.h>
#include <Turn.h>

//Define Functions

/*SingleSourceMovesList *FindSingleSourceOptimalMove(SingleSourceMovesTree *moves_tree); //2
MultipleSourceMovesList *FindAllPossiblePlayerMoves(Board board, Player player); //3
void Turn(Board board, Player player); //4
void StorBoard(Board board, char *filename); //5
void LoadBoard(char *filename, Board board); //6
void PlayGame(Board board, Player starting_player); //7*/

void main()
{

    Board board;
    createBoard(board);
    /*board[2][3]=BOTTOM_PLAYER;
    board[2][5]=BOTTOM_PLAYER;
    board[4][5]=BOTTOM_PLAYER;
    board[5][4]=SYMBOL;*/

    board[0][1]=SYMBOL;
    board[1][4]=SYMBOL;
    board[2][3]=SYMBOL;
    board[3][4]=TOP_PLAYER;
    board[4][1]=TOP_PLAYER;
    board[4][3]=TOP_PLAYER;
    board[5][4]=TOP_PLAYER;

    //StoreBoard(board);
    //printBoard(board);
    Turn(board,BOTTOM_PLAYER);
    printBoard(board);

    // printBoard(board);
}