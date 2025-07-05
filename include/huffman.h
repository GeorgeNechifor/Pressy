#ifndef _huffman_
#define _huffman_
#include<stdlib.h>
#include<stdio.h>
#include"./fileutils.h"
#include<string.h>

typedef struct huffman{
    unsigned int freq;
    unsigned char val;
    struct huffman * left;
    struct huffman * right;
} huffman;

typedef struct huffmancode{
    unsigned long long code[256];
    unsigned long long codelength[256];
} huffmancode;

huffman * createnode(unsigned int freq , unsigned char val , huffman * l , huffman * r);

void destroy(huffman * root);

void concatbin(int bin , unsigned long long bincode);

void generatehuffmancodes(huffman * root , int path[] , int pathlength , huffmancode * hc);


#endif
