#include <createBoard.h>
#include <General.h>

void createBoard(Board board,Player playerA,Player playerB)
{
    int row,col, sizeHalfBoard=(BOARD_SIZE/2)-1;

    buildThirdBoard(board,0,sizeHalfBoard,playerA,SYMBOL);
    for(row = sizeHalfBoard; row < sizeHalfBoard + 2; row++)
    {
        for(col = 0; col < BOARD_SIZE; col++)
        {
            board[row][col]=SYMBOL;
        }
    }
    buildThirdBoard(board,sizeHalfBoard + 2,BOARD_SIZE,playerB,SYMBOL);
}

void buildThirdBoard(Board board,unsigned int firstRow,unsigned int endRow,Player player,char symbol)
{
    int row, col;
    char firstChar, secondChar;
    for (row = firstRow; row < endRow; row++)
    {
        if (row % 2 == 0) {
            firstChar = symbol;
            secondChar = player;
        } else {
            firstChar = player;
            secondChar = symbol;
        }
        for (col = 0; col < BOARD_SIZE; col = col + 2) {
            board[row][col]=firstChar;
            board[row][col+1]=secondChar;

        }
    }
}