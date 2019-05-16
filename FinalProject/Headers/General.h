#pragma once

#define BOARD_SIZE 8

typedef struct _checkersPos
{
    char row,col;
} checkersPos;

typedef unsigned char Board[BOARD_SIZE][BOARD_SIZE];
const unsigned char SYMBOL=' ';
typedef unsigned char Player;

const Player PLAYER_A='B';
const Player PLAYER_B='T';

//1
typedef struct _SingleSourceMovesTreeNode{
    Board  board;
    checkersPos *pos;
    unsigned short total_captures_so_far;
    struct _SingleSourceMovesReeNode  *next_move[2];
} SingleSourceMovesTreeNode;

typedef struct _SingleSourceMovesTree {
    SingleSourceMovesTreeNode *source;
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