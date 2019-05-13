//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define BOARD_SIZE 8

typedef struct _checkersPos
{
    char row,col;
} checkersPos;

typedef unsigned char Board[BOARD_SIZE][BOARD_SIZE];

typedef unsigned char Player;

typedef unsigned char Player;

//1
typedef struct _SingleSourceMovesTreeNode{
    Board   board;
    checkersPos *pos;
    unsigned short total_captures_so_far;
    struct _SingleSourceMovesReeNode  *next_move[2];
} SingleSourceMovesTreeNode;

typedef struct _SingleSourceMovesRee {
    singleSoutceMovesTreeNode;
} SingleSourceMovesTree;

//2
typedef struct _SingleSourceMovesListCell {
    checkersPos *position;
    unsigned short captures;
    struct _SingleSourceMovesListCell;
} SingleSourceMovesListCell;

typedef struct _SingleSourceMovesList {
    SingleSourceMovesListCell *head;
    SingleSourceMovesListCell *tail;
} SingleSourceMovesList;

//3
typedef struct _multipleSourceMovesListCell {
    SingleSourceMovesList *single_source_moves_list;
    struct _multipleSourceMovesListCell *next;
} MultipleSourceMovesListCell;

typedef struct _multipleSourceMovesList {
    MultipleSourceMovesListCell *head;
    MultipleSourceMovesListCell *tai;
} MultipleSourceMovesList;

//Define Functions
SingleSourceMovesTree *FindSingleSourceMoves(Board board, checkersPos *src); //1
SingleSourceMovesList *FindSingleSourceOptimalMove(SingleSourceMovesTree *moves_tree); //2
MultipleSourceMovesList *FindAllPossiblePlayerMoves(Board board, Player player); //3
void Turn(Board board, Player player); //4
void StorBoard(Board board, char *filename); //5
void LoadBoard(char *filename, Board board); //6
void PlayGame(Board board, Player starting_player); //7