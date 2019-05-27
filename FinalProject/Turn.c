
#include <General.h>
#include <stdlib.h>
#include <List.h>
#include <Tree.h>
#include <FindAllPossiblePlayerMoves.h>

void Turn(Board board, Player player)
{
    SingleSourceMovesListCell* currL; //single List
    SingleSourceMovesList turnList; //Selected list
    MultipleSourceMovesListCell* currLol; //Multiple list cell
    MultipleSourceMovesList* listOfLists; //Multiple list
    unsigned short maxCaptures=0,currListCaptures;
    char currPlayer;
    int firstCol,firstRow,secondCol,secondRow,moveCol,moveRow;

  //  makeEmptyListOfLists(listOfLists);
    listOfLists=FindAllPossiblePlayerMoves(board,player);
    currLol=listOfLists->head;

    //Find the best route
    if(player==TOP_PLAYER)
        currPlayer=TOP_PLAYER;
    else if(player==BOTTOM_PLAYER)
        currPlayer=BOTTOM_PLAYER;

        while (currLol != NULL)
        {
            currListCaptures = currLol->single_source_moves_list->tail->captures;

            if (currListCaptures >= maxCaptures)
            {
                maxCaptures = currListCaptures;
                turnList = *(currLol->single_source_moves_list);
            }
            currLol = currLol->next;
        }

        //Make the turn
        currL = turnList.head;
        while (currL->next != NULL)
        {
            firstCol=currL->position->col - '0';
            firstRow=currL->position->row - '0';
            secondCol=currL->next->position->col - '0';
            secondRow=currL->next->position->row - '0';

            //Check if next turn is without eating
            if(currL->next->captures == 0)
            {
                board[firstRow][firstCol] = SYMBOL;
                board[secondRow][secondCol] = currPlayer;
            }
            //Check if next turn is with eating
            else if(currL->next->captures >= 1)
            {
                moveCol=(secondCol - firstCol) / 2;
                moveRow=(secondRow - firstRow) / 2;
                board[firstRow][firstCol] = SYMBOL;
                board[firstRow+moveRow][firstCol+moveCol] = SYMBOL;
                board[secondRow][secondCol] = currPlayer;
            }
            currL=currL->next;
        }
    //Free to the list of lists and all the lists inside of it
}