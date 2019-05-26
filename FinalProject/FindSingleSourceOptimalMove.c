#include <General.h>
#include <stdlib.h>
#include <List.h>
#include <Tree.h>
#include <FindSingleSourceOptimalMove.h>

SingleSourceMovesList *FindSingleSourceOptimalMove(SingleSourceMovesTree *moves_tree)
{
    int length=0;
    SingleSourceMovesList* lst;
    lst = (SingleSourceMovesList*)malloc(sizeof(SingleSourceMovesList));
    cleanBranches(moves_tree->source,&length);
    makeEmptyList(lst);
    buildList(lst,moves_tree->source);
    return lst;
}

void cleanBranches(SingleSourceMovesTreeNode* curr, int* length)
{
    int lengthLeft=0,lengthRight=0;

    if(curr->next_move[RIGHT_MOVE_INDEX] == NULL && curr->next_move[LEFT_MOVE_INDEX] == NULL)
    {
        *length=0;
        return;
    }
    else
    {
        if(curr->next_move[RIGHT_MOVE_INDEX] != NULL)
        {
            cleanBranches(curr->next_move[RIGHT_MOVE_INDEX],&lengthRight);
            lengthRight++;
        }
        if(curr->next_move[LEFT_MOVE_INDEX] != NULL)
        {
            cleanBranches(curr->next_move[LEFT_MOVE_INDEX],&lengthLeft);
            lengthLeft++;
        }
        if(lengthLeft >= lengthRight)
        {
            *length=lengthLeft;
            freeTreeRec(curr->next_move[RIGHT_MOVE_INDEX]);
            curr->next_move[RIGHT_MOVE_INDEX]=NULL;
        }
        else
        {
            *length=lengthRight;
            freeTreeRec(curr->next_move[LEFT_MOVE_INDEX]);
            curr->next_move[LEFT_MOVE_INDEX]=NULL;
        }
    }
}

void buildList(SingleSourceMovesList* lst,SingleSourceMovesTreeNode* currTreeNode)
{
    if(currTreeNode->next_move[RIGHT_MOVE_INDEX] == NULL && currTreeNode->next_move[LEFT_MOVE_INDEX] == NULL)
    {
       // currListNode=createNewListNode(*(curr->pos),curr->total_captures_so_far,NULL);
        insertDataToEndList(lst, *(currTreeNode->pos), currTreeNode->total_captures_so_far);
    }
    else
    {
        //currListNode=createNewListNode(*(curr->pos),curr->total_captures_so_far,NULL);
        insertDataToEndList(lst, *(currTreeNode->pos), currTreeNode->total_captures_so_far);
        if(currTreeNode->next_move[RIGHT_MOVE_INDEX] != NULL)
        {
            buildList(lst,currTreeNode->next_move[RIGHT_MOVE_INDEX]);
           // currListNode->next=buildList(curr->next_move[RIGHT_MOVE_INDEX]);
        }
        else if(currTreeNode->next_move[LEFT_MOVE_INDEX] != NULL)
        {
            //currListNode->next=buildList(curr->next_move[LEFT_MOVE_INDEX]);
            buildList(lst,currTreeNode->next_move[LEFT_MOVE_INDEX]);
        }
    }
}