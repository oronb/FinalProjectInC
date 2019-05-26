#include <stdlib.h>
#include <General.h>
#include <List.h>

/*typedef struct _SingleSourceMovesTreeNode{
    Board board;
    checkersPos *pos;
    unsigned short total_captures_so_far;
    struct _SingleSourceMovesTreeNode  *next_move[2];
} SingleSourceMovesTreeNode;

typedef struct _SingleSourceMovesTree {
    SingleSourceMovesTreeNode *source;
} SingleSourceMovesTree;

typedef struct _SingleSourceMovesListCell {
    checkersPos *position;
    unsigned short captures;
    struct _SingleSourceMovesListCell *next;
} SingleSourceMovesListCell;

typedef struct _SingleSourceMovesList {
    SingleSourceMovesListCell *head;
    SingleSourceMovesListCell *tail;
} SingleSourceMovesList;*/

void makeEmptyList(SingleSourceMovesList* lst)
{
    (*lst).head = (*lst).tail = NULL;
}

void insertDataToEndList(SingleSourceMovesList* lst, checkersPos position, unsigned short captures)
{
    SingleSourceMovesListCell* newTail;

    newTail = createNewListNode(position, captures, NULL);
    insertNodeToEndList(lst, newTail);
}

SingleSourceMovesListCell* createNewListNode(checkersPos position, unsigned short captures, SingleSourceMovesListCell* next)
{
    SingleSourceMovesListCell* res;

    res = (SingleSourceMovesListCell*)malloc(sizeof(SingleSourceMovesListCell));
    //checkAlloc(res);
    res->position = (checkersPos*)malloc(sizeof(checkersPos));
    res->position->row=position.row;
    res->position->col=position.col;
    res->captures = captures;
    res->next = next;

    return res;
}

void insertNodeToEndList(SingleSourceMovesList* lst, SingleSourceMovesListCell * newTail) {
    if (isEmptyList(lst))
    {
        lst->head = lst->tail = newTail;
    }
    else
    {
        lst->tail->next = newTail;
        lst->tail = newTail;
    }
}

int isEmptyList(const SingleSourceMovesList* lst)
{
    return lst->head == NULL;
}