//#define _CRT_SECURE_NO_WARNINGS
//Maissa
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <General.h>
#include <createBoard.h>
#include <printBoard.h>

const Player PLAYER_A='B';
const Player PLAYER_B='T';
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
    createBoard(board,PLAYER_A,PLAYER_B);
    printBoard(board);
}