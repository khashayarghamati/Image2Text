// write2image.cpp : Defines the entry point for the console application.
//
#include<stdio.h>
#include<stdlib.h>
//#include "stdafx.h"

int length;
unsigned char *inData;  
char Buffer[9];
int c = 0, x;
int main()
{
FILE* pInput = fopen("file.txt", "r"); 
FILE* pOutput = fopen("output.bmp","w+");

unsigned char index = 0, byte = 0;

char line[32]; // Arbitrary, few characters should be enough

while (fgets(line, sizeof(line), pInput))
{
    if (line[0] == '1')
        byte = (unsigned char)(byte | (1 << index));

    if (++index == 8)
    {
        fwrite(&byte, 1, 1, pOutput);

        index = 0;
        byte = 0;
    }
}


fclose(pOutput);
fclose(pInput);

}

