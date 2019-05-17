#pragma once

#include <General.h>

SingleSourceMovesTree *FindSingleSourceMoves(Board board, checkersPos *src);
SingleSourceMovesTreeNode* FindSingleSourceMovesRec(Board board, char row, char col,Player currPlayer, Player otherPlayer);
BOOL checkIfPlayerReachedToTheEnd(Player currPlayer, int row, int col);
BOOL checkIfReachToTopOfBoard(row,col);
BOOL checkMoveOfPlayer(Board board,int row,int col,char currPlayer,char otherPlayer,char currSquareSymbol, BOOL* canMoveLeft,BOOL* canMoveRight);
BOOL canMoveToNextSquare(Board board, nextRow,nextCol,currPlayer,otherPlayer,currSquareSymbol);