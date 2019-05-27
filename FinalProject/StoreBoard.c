#include <StoreBoard.h>
#include <stdio.h>
#include <stdlib.h>

//void checkFile(FILE *fp);
//void writeToFile(char *fName, STUDENT *arr, int size);
//void printStudArr(STUDENT *arr, int size);
//void readFromFile(char *fName, STUDENT **arr, int *size);

//void StoreBoard(Board board, char *filename)
void StoreBoard(Board board)
{
    int i,j,c,r,b;
    unsigned char mask[4];
    unsigned char bits[16];
    char ch;
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

/*void writeToFile(char *fName, STUDENT *arr, int size)
{
    int num, i, nameLen;
    FILE *fp;


    // writting to File:
    fp = fopen(fName, "wb");
    checkFile(fp);

    printf("Array size is : %d\n", size);
    fwrite(&size, sizeof(int), 1, fp);
    for (i = 0; i < size; i++)
    {
        nameLen = strlen(arr[i].name)+1;
        printf("Name %s Length = %d ", arr[i].name, nameLen);
        fwrite(&nameLen, sizeof(int), 1, fp);
        fwrite(arr[i].name, sizeof(char), nameLen, fp);
        printf("Avergae Grade = %.1lf\n", arr[i].avgGrade);
        fwrite(&arr[i].avgGrade, sizeof(double), 1, fp);
    }

    fclose(fp);
}

void checkFile(FILE *fp)
{
    if (fp == NULL)
    {
        printf("Failed opening the file. Exiting!\n");
        exit(0);
    }
}*/
