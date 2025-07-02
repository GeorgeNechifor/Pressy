#ifndef _minheap_
#define _minheap_
#include<stdio.h>
#include<stdlib.h>
#include"./huffman.h"
#define MAX_SIZE 256

typedef struct minheap{
    unsigned int size;
    huffman *data[MAX_SIZE];
} minheap;

void createheap(minheap * heap);

void heapinsert(minheap* heap , huffman * node);

huffman * heapextractmin(minheap * heap);



#endif