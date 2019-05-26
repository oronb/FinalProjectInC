
#include <FindAllPossiblePlayerMoves.h>
#include <General.h>
#include <List.h>
#include <Tree.h>
#include <FindSingleSourceMoves.h>
#include <FindSingleSourceOptimalMove.h>
#include <stdlib.h>

/*
 * typedef struct _multipleSourceMovesListCell {
    SingleSourceMovesList *single_source_moves_list;
    struct _multipleSourceMovesListCell *next;
} MultipleSourceMovesListCell;

typedef struct _multipleSourceMovesList {
    MultipleSourceMovesListCell *head;
    MultipleSourceMovesListCell *tai;
} MultipleSourceMovesList;
 */
MultipleSourceMovesList* FindAllPossiblePlayerMoves(Board board, Player player)
{
    int r,c;
    checkersPos pos;
    SingleSourceMovesTree* tree;
    SingleSourceMovesList* lst;
    MultipleSourceMovesList listOfLists;

    for(r = 1; r < BOARD_SIZE; r++)
    {
        for(c = 0; c < BOARD_SIZE; c++)
        {
            //Check if player exists in position
            if(board[r][c] == player)
            {
                pos.row=r;
                pos.col=c;
                tree=FindSingleSourceMoves(board,&pos);
                if(tree != NULL)
                {
                    lst=FindSingleSourceOptimalMove(tree);
                    insertDataToEndListOfLists(&listOfLists,lst);
                }
            }
        }
    }

}