#include <stdio.h>
#include"../include/huffman.h"
#include"../include/fileutils.h"
#include"../include/minheap.h"

int main(int argc , char * argv[]) {



    int path[1000];
    int pathlength = 0;
    huffmancode * hc = (huffmancode*)malloc(sizeof(huffmancode));
    minheap * heap = (minheap*) malloc(sizeof(minheap));
    createheap(heap);
    huffman * root = NULL;
    makeheap(heap , argc , argv);
    makehuffman(heap);
    root = heapextractmin(heap);
    generatehuffmancodes(root ,path , pathlength , hc);

    for(int i = 0; i < 256;++i){
        if(hc->code[i]) printf("%llu\n" , hc->codelength[i]);
    }


    free(heap);
    destroy(root);
    free(hc);

    return 0;
}
