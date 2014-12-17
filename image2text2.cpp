// image2text2.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>


int main(int argc, _TCHAR* argv[])
{



char *buffer;
int fileLen;
FILE *file = fopen("output.jpg", "rb");
FILE* pOutput = fopen("file.txt", "w");

fseek(file, 0, SEEK_END);
fileLen=ftell(file);
fseek(file, 0, SEEK_SET);

buffer=(char *)malloc(fileLen+1);
fread(buffer, fileLen, 1, file);

//convertToBit(&buffer, fileLen);
free(buffer);



// convert buffer data to bits and write them to a text file   





    for (size_t i=0; i < fileLen; ++i)
    {
        unsigned char byte = (unsigned char)buffer[i];

        for (int bitIndex=0; bitIndex < 8; ++bitIndex)
        {
            if ((byte & (1 << bitIndex)) != 0)
                fputs("1", pOutput);
            else
                fputs("0", pOutput);
        }
    }


    fclose(pOutput);
    fclose(file);
}



