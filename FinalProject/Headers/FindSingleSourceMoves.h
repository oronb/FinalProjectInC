#pragma once
#include <General.h>

SingleSourceMovesTree *FindSingleSourceMoves(Board board, checkersPos *src);
SingleSourceMovesTreeNode* FindSingleSourceMovesRec(Board board, int row, int col,Player currPlayer, Player otherPlayer);
BOOL checkIfPlayerReachedToTheEnd(Player currPlayer, int row, int col);
BOOL checkIfReachToEndOfBoard(int row,int col);
BOOL checkIfReachToTopOfBoard(int row,int col);
void checkMoveOfPlayer(Board board,int row,int col,char currPlayer,char otherPlayer,unsigned char currSquareSymbol, BOOL* canMoveLeft,BOOL* canMoveRight);
BOOL canMoveToNextSquare(Board board, int nextRow,int nextCol,Player currPlayer,Player otherPlayer,unsigned char currSquareSymbol);
void copyBoard(Board sourceBoard, Board destBoard);
//Check if reached to the right end of the board
BOOL checkIfReachToRightEndOfBoard(int row,int col);
//Check if reached to the left end of the board
BOOL checkIfReachToLeftEndOfBoard(int row,int col);