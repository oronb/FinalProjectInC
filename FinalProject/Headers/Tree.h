#pragma once
#include <General.h>

void printTree(SingleSourceMovesTree tree);
void printTreeRec(SingleSourceMovesTreeNode* curr);
SingleSourceMovesTreeNode* createNewTreeNode(Board board, char row, char col);