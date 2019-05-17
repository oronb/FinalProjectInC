#include <General.h>
#include <Tree.h>

SingleSourceMovesTreeNode* createNewTreeNode(Board board, char row, char col, unsigned short total_captures_so_far)
{
    //Define variables
    SingleSourceMovesTreeNode curr;
    SingleSourceMovesTreeNode* next_move[NEXT_MOVE_SIZE];

    //create tree node
    curr=(SingleSourceMovesTreeNode*)malloc(sizeof(SingleSourceMovesTreeNode);
    //create pos
    pos=(checkersPos*)malloc(sizeof(checkersPos));
    //create newMove
    next_move=(SingleSourceMovesTreeNode**)malloc(sizeof(SingleSourceMovesTreeNode) * NEXT_MOVE_SIZE);

    //Setting the tree node
    curr->board=board;
    *(curr->pos).col=col;
    *(curr->pos).row=row;
    curr->total_captures_so_far=0;
    curr->next_move[RIGHT_MOVE_INDEX]=NULL;
    curr->next_move=[LEFT_MOVE_INDEX]=NULL;

    return SingleSourceMovesTreeNode*;
}

