#include <TestingFindSingleSourceMoves.h>
#include <FindSingleSourceMoves.h>
#include <General.h>
#include <stdio.h>
#include <Tree.h>

void TestingFindSingleSourceMoves(Board board)
{
    SingleSourceMovesTree* tr;
    checkersPos checkersPos1;
    checkersPos1.row='0';
    checkersPos1.col='1';
    printf("Board is initialized\n");
    printf("Checking What is the source moved of top player in row 0 column 1\n");
    tr=FindSingleSourceMoves( board, &checkersPos1);
    printTree(*tr);
}