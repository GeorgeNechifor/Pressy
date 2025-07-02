#include <stdio.h>
#include"../include/huffman.h"
#include"../include/fileutils.h"
#include"../include/minheap.h"

int main(int argc , char ** argv) {

    minheap * heap = (minheap*)malloc(sizeof(minheap));

    createheap(heap);
    huffman * node = NULL;
    for(int i = 4; i < 10;++i){
        node = createnode(i,1,NULL , NULL);
        heapinsert(heap , node);
    }
    node = heapextractmin(heap);
    printf("%d " , node->freq);

    free(node);
    free(heap);

    return 0;
}
