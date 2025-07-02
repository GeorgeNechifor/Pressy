#include"../include/fileutils.h"

fileutils * createfileutils(){
    fileutils * file = (fileutils*) malloc(sizeof(fileutils));
    for(int i = 0; i < MAX_SIZE;++i){
        file->freq[i] = 0;
    }
    return file;
}

void makefile(int argc,  char *argv[] , fileutils * file){
    if(argc != 2) exit(EXIT_FAILURE);

    FILE * inputfile = fopen(argv[1] , "rb");
    if(!inputfile){
        perror("Invalid file!");
        exit(EXIT_FAILURE);
    }
    unsigned char byte;
    while(fread(&byte , 1 , 1 , inputfile)){
        file->freq[byte]++;
    }
    fclose(inputfile);
}