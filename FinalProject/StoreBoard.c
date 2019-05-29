#include <General.h>
#include <StoreBoard.h>
#include <stdio.h>
#include <stdlib.h>
#include <printBoard.h>

//void checkFile(FILE *fp);
//void writeToFile(char *fName, STUDENT *arr, int size);
//void printStudArr(STUDENT *arr, int size);
//void readFromFile(char *fName, STUDENT **arr, int *size);

//void StoreBoard(Board board, char *filename)
void StoreBoard(Board board)
{
    int i,j,c,r,b;
    //char boardA[4][4];
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

    for(i=0;i<16;i=i+2)
    {
        printCharAsBinary(bits[i]);
        printCharAsBinary(bits[i+1]);
        printf("\n");
    }
    //Writing to file
    char* file="board.bin";
    writeToFile(file, bits, 16);
    //readFromFile(file, boardA);
    //printBoard(boardA);

}



void printCharAsBinary(char ch)
{
    int i;
    unsigned char temp;
    for(i=0;i<8;i++)
    {
        temp=ch<<i;
        temp=temp>>7;
        printf("%d",temp);
    }
}

void checkFile(FILE *fp)
{
    if (fp == NULL)
    {
        printf("Failed opening the file. Exiting!\n");
        exit(0);
    }
}

void writeToFile(char *fName, unsigned char * arr, int size)
{
    int i;
    FILE *fp;


    // writting to File:
    fp = fopen(fName, "w");
    checkFile(fp);

    for (i = 0; i < size; i=i+2)
    {
        fwrite(arr +i, sizeof(unsigned char), 2, fp);
    }

    fclose(fp);
}


/*void readFromFile(char *fName, char board[4][4])
{
    FILE *fp;
    int r, c;

    // reading to File:
    fp = fopen(fName, "rb");
    checkFile(fp);

    for (r = 0; r < 4; r++)
    {
        for(c = 0; c < 4; c++)
        {
            fread(&board[r][c], sizeof(unsigned char), 1, fp);
            printf("Reading row %d and col %d\n", r,c);
        }
    }

    fclose(fp);
}*/
