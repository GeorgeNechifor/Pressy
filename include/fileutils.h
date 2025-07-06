#ifndef _fileutils_
#define _fileutils_
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 256
#define MAX_LENGTH 1024

typedef struct fileutils{
    unsigned int freq[MAX_SIZE];
    FILE * inputfile;
    FILE * outputfile;
    char outputfilename[MAX_LENGTH];
} fileutils;

fileutils * createfileutils();

void makeinputfile(int argc , char * argv[] , fileutils * file);

void generateinputfilename(const char * inputpath , char * outputpath , size_t maxlength);

void makeoutputfile(int argc , char * argv[] , fileutils * file);

#endif