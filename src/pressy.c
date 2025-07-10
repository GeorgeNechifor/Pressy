#include"../include/pressy.h"

pressy * createpressy(){
    pressy * p = (pressy*)malloc(sizeof(pressy));
    p->hc = (huffmancode*) malloc(sizeof(huffmancode));
    p->heap = (minheap*)malloc(sizeof(minheap));
    p->file = createfileutils();
    p->root = NULL;
    p->pathlength = 0;
    p->hc->nodes = 0;
    createheap(p->heap);
    return p;
}

void run(int argc , char * argv[] , pressy * p){
    if(argc == 1){
        printf("Version 1.0.0");
        exit(EXIT_SUCCESS);
    }
    else if(argc == 2){
        if(strcmp(argv[1] , "-help") == 0){
            printf("Pressy 1.0.0\n");
            printf("How to use Pressy:\n");
            printf("    -press   creates a new Pressy file at the same adress.\n");
            printf("    -extract decompress the Pressy file.");

        }
        else{
            fprintf(stderr , "Invalid input!\n");
            exit(EXIT_FAILURE);
        }
    }
    else if(argc == 3){
        if(strcmp(argv[2] , "-press") == 0){
            makeheap(p->heap , argc , argv , p->file);
            makehuffman(p->heap);
            p->root = heapextractmin(p->heap);
            generatehuffmancodes(p->root , p->path , p->pathlength , p->hc);
            compress(p->hc,p->file,p->root);
        }
        else if(strcmp(argv[2] , "-extract") == 0){
            fprintf(stderr , "extract nod defined");
            exit(EXIT_FAILURE);
        }
        else{
            fprintf(stderr , "Invalid command!");
            exit(EXIT_FAILURE);
        }
    }
    else{
        fprintf(stderr , "Invalid input!\n");
        exit(EXIT_FAILURE);
    }
}

void clearmemo(pressy * p){
    fclose(p->file->outputfile);
    free(p->heap);
    destroy(p->root);
    free(p->file);
    free(p->hc);
    free(p);
}