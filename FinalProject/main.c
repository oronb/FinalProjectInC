//#define _CRT_SECURE_NO_WARNINGS
//Maissa
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <createBoard.h>
#include <printBoard.h>
#include <General.h>

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
    printBoard(board);
}