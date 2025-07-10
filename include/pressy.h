#ifndef _pressy_
#define _pressy_
#define MAX_SIZE 256
#include"./huffman.h"
#include"./minheap.h"

typedef struct pressy{
    int path[MAX_SIZE];
    int pathlength;
    huffman * root;
    huffmancode * hc;
    minheap * heap;
    fileutils * file;
} pressy;

pressy * createpressy();

void run(int argc , char * argv[] , pressy * p);

void clearmemo(pressy * p);

#endif