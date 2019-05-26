#include <printBoard.h>

void printBoard(Board board)
{
    unsigned int r,c;
    for(r = 0; r < BOARD_SIZE; r++)
    {
        for(c = 0; c < BOARD_SIZE; c++)
        {
            printf("%c ", board[r][c]);
        }
        printf("\n");
    }
}