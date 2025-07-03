#include <stdio.h>
#include"../include/huffman.h"
#include"../include/fileutils.h"
#include"../include/minheap.h"

int main(int argc , char * argv[]) {



    minheap * heap = (minheap*) malloc(sizeof(minheap));
    createheap(heap);
    huffman * root = NULL;
    makeheap(heap , argc , argv);
    makehuffman(heap);
    root = heapextractmin(heap);

    free(heap);
    destroy(root);

    return 0;
}
