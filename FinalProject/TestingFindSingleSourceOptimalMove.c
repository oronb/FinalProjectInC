#include <TestingFindSingleSourceMoves.h>
#include <TestingFindSingleSourceOptimalMove.h>
#include <FindSingleSourceOptimalMove.h>
#include <FindSingleSourceMoves.h>
#include <General.h>
#include <stdio.h>
#include <Tree.h>
#include <stdlib.h>

void TestingFindSingleSourceOptimalMove(Board board)
{
        //Testing top player
        /*board[6][3]=SYMBOL;
        board[5][6]=SYMBOL;
        board[3][4]=BOTTOM_PLAYER;
         */
        //Testing bottom player
        int length=0;
        board[2][3]=BOTTOM_PLAYER;
        board[2][5]=BOTTOM_PLAYER;
        board[4][5]=BOTTOM_PLAYER;
        board[5][4]=SYMBOL;
        SingleSourceMovesTree* tr;
        SingleSourceMovesList* lst;
        lst = (SingleSourceMovesList*)malloc(sizeof(SingleSourceMovesList));
        checkersPos checkersPos1;
        printf("Enter row and column\n");
        scanf("%c %c",&checkersPos1.row,&checkersPos1.col);
        printf("Board is initialized\n");
        printf("Checking What is the source moved of top player in row %c column %c\n",checkersPos1.row, checkersPos1.col );
        tr=FindSingleSourceMoves( board, &checkersPos1);
        lst=FindSingleSourceOptimalMove(tr);


    //printTree(*tr);
}