#include <stdio.h>
#include <stdlib.h>
#include <General.h>
#include <File.h>

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
    fp = fopen(fName, "wb");
    checkFile(fp);

    for (i = 0; i < size; i=i+2)
    {
        fwrite(arr +i, sizeof(unsigned char), 2, fp);
    }

    fclose(fp);
}

