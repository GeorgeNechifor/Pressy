#include <stdio.h>
#include"../include/huffman.h"
#include"../include/fileutils.h"
#include"../include/minheap.h"

int main(int argc , char * argv[]) {



    int path[256];
    int pathlength = 0;
    huffmancode * hc = (huffmancode*)malloc(sizeof(huffmancode));
    minheap * heap = (minheap*) malloc(sizeof(minheap));
    fileutils * file = createfileutils();
    createheap(heap);
    huffman * root = NULL;
    makeheap(heap , argc , argv , file);
    makehuffman(heap);
    root = heapextractmin(heap);
    generatehuffmancodes(root ,path , pathlength , hc);
    compress(hc , file);




    fclose(file->outputfile);
    free(heap);
    destroy(root);
    free(hc);
    free(file);

    return 0;
}
