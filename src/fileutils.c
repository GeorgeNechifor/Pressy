#include"../include/fileutils.h"

fileutils * createfileutils(){
    fileutils * file = (fileutils*) malloc(sizeof(fileutils));
    for(int i = 0; i < MAX_SIZE;++i){
        file->freq[i] = 0;
    }
    file->inputfile = NULL;
    file->outputfile = NULL;
    return file;
}

void makeinputfile(int argc,  char *argv[] , fileutils * file){
    if(argc != 2) exit(EXIT_FAILURE);

    file->inputfile = fopen(argv[1] , "rb");
    if(!file->inputfile){
        perror("Invalid file!");
        exit(EXIT_FAILURE);
    }
    unsigned char byte;
    while(fread(&byte , 1 , 1 , file->inputfile)){
        file->freq[byte]++;
    }
    fclose(file->inputfile);
}

void generateinputfilename(const char * inputpath , char * outputpath , size_t maxlength){
    strncpy(outputpath, inputpath, maxlength);
    outputpath[maxlength - 1] = '\0';

    char *dot = strrchr(outputpath, '.');

    if (dot && strrchr(dot, '/') == NULL) {
        strcpy(dot, ".psy");
    } else {
        strncat(outputpath, ".huf", maxlength - strlen(outputpath) - 1);
    }
}

void makeoutputfile(int argc , char * argv[] , fileutils * file){
    if(argc != 2) exit(EXIT_FAILURE);

    generateinputfilename(argv[1] , file->outputfilename , sizeof(file->outputfilename));
    file->outputfile = fopen(file->outputfilename , "wb");
    if(!file->outputfile){
        exit(EXIT_FAILURE);
    }
}