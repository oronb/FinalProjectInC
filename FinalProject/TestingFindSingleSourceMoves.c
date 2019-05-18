#include <TestingFindSingleSourceMoves.h>
#include <FindSingleSourceMoves.h>
#include <General.h>
#include <stdio.h>
#include <Tree.h>

void TestingFindSingleSourceMoves(Board board)
{
    SingleSourceMovesTree* tr;
    checkersPos checkersPos1;
    printf("Enter row and column\n");
    scanf("%c %c",&checkersPos1.row,&checkersPos1.col);
    printf("Board is initialized\n");
    printf("Checking What is the source moved of top player in row %c column %c\n",checkersPos1.row, checkersPos1.col );
    tr=FindSingleSourceMoves( board, &checkersPos1);
    printTree(*tr);
}
