#include <General.h>
#include <StoreBoard.h>
#include <stdio.h>
#include <stdlib.h>
#include <printBoard.h>
#include <File.h>


//void StoreBoard(Board board, char *filename)
void StoreBoard(Board board)
{
    int i,j,c,r,b;
    Board boardA;
    unsigned char mask[4];
    unsigned char bits[16];
    char one=1;

    for(r = 0,b = 0; r < BOARD_SIZE; r++,b=b+2)
    {
        for(c = 0,i=1,j=0; c < BOARD_SIZE/2; c++,i++,j++)
        {

            if(board[r][c] == TOP_PLAYER)
            {
                mask[j] = (one << (BOARD_SIZE - i*2));
            }
            else if(board[r][c] == BOTTOM_PLAYER)
            {
                mask[j] = (one << (BOARD_SIZE - i - j));
            }
            else if(board[r][c] == SYMBOL)
            {
                mask[j] = 0;
            }
        }
        bits[b] = mask[0] | mask[1] | mask[2] | mask[3];
        for(c = BOARD_SIZE/2,i=1,j=0; c < BOARD_SIZE; c++,i++,j++)
        {

            if(board[r][c] == TOP_PLAYER)
            {
                mask[j] = (one << (BOARD_SIZE - i*2));
            }
            else if(board[r][c] == BOTTOM_PLAYER)
            {
                mask[j] = (one << (BOARD_SIZE - i - j));
            }
            else if(board[r][c] == SYMBOL)
            {
                mask[j] = 0;
            }
        }
        bits[b+1] = mask[0] | mask[1] | mask[2] | mask[3];
    }

   /* for(i=0;i<16;i=i+2)
    {
        printCharAsBinary(bits[i]);
        printCharAsBinary(bits[i+1]);
        printf("\n");
    }*/

    //Writing to file
    char* file="board.bin";
    writeToFile(file, bits, 16);

}


/*void printCharAsBinary(char ch)
{
    int i;
    unsigned char temp;
    for(i=0;i<8;i++)
    {
        temp=ch<<i;
        temp=temp>>7;
        printf("%d",temp);
    }
}*/

