#include <General.h>
#include <Tree.h>
#include <printBoard.h>
#include <FindSingleSourceMoves.h>
#include <stdlib.h>

SingleSourceMovesTreeNode* createNewTreeNode(Board board, char row, char col)
{
    //Define variables
    SingleSourceMovesTreeNode* curr;
    //create tree node
    curr=(SingleSourceMovesTreeNode*)malloc(sizeof(SingleSourceMovesTreeNode));
    //create pos

    //Setting the tree node
    //In Marking just for debugging!
    // copyBoard(board,curr->board);
    curr->pos=(checkersPos*)malloc(sizeof(checkersPos));
    curr->pos->col=col;
    curr->pos->row=row;
    curr->total_captures_so_far=0;
    curr->next_move[RIGHT_MOVE_INDEX]=NULL;
    curr->next_move[LEFT_MOVE_INDEX]=NULL;

    return curr;
}

void printTree(SingleSourceMovesTree tree)
{
    SingleSourceMovesTreeNode* curr=tree.source;
    printTreeRec(curr);
}

void printTreeRec(SingleSourceMovesTreeNode* curr)
{
    if(curr==NULL)
    {
        return;
    }
    else
    {
        printTreeRec(curr->next_move[LEFT_MOVE_INDEX]);
        printf("The board is:\n");
        //printBoard(curr->board);
        printf("The checkers is:\n");
        printf("The row is:%d\nThe column is: %d\n",curr->pos->row,curr->pos->col);
        printf("Total captures so far: %d\n", curr->total_captures_so_far);
        printf("\n\n");
        printTreeRec(curr->next_move[RIGHT_MOVE_INDEX]);

    }

}

void freeTree(SingleSourceMovesTree tr)
{
    freeTreeRec(tr.source);
}

//FreeTreeRec() function recursively free all tree nodes.
void freeTreeRec(SingleSourceMovesTreeNode *root)
{
    if (root != NULL)
    {
        freeTreeRec(root->next_move[RIGHT_MOVE_INDEX]);
        freeTreeRec(root->next_move[LEFT_MOVE_INDEX]);
        free(root->pos);
        free(root);
    }
}