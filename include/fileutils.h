#ifndef _fileutils_
#define _fileutils_
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 256

typedef struct fileutils{
    unsigned int freq[MAX_SIZE];
} fileutils;

fileutils * createfileutils();

void makefile(int argc , char * argv[] , fileutils * file);

#endif