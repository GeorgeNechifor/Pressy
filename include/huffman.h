#ifndef _huffman_
#define _huffman_
#include<stdlib.h>
#include<stdio.h>
#include"./fileutils.h"
#include<string.h>
#define MAX_SIZE 256

typedef struct huffman{
    unsigned int freq;
    unsigned char val;
    struct huffman * left;
    struct huffman * right;
} huffman;

typedef struct huffmancode{
    unsigned long long code[MAX_SIZE];
    unsigned int codelength[MAX_SIZE];
    unsigned int nodes;
} huffmancode;

huffman * createnode(unsigned int freq , unsigned char val , huffman * l , huffman * r);

void destroy(huffman * root);

void generatehuffmancodes(huffman * root , int path[] , int pathlength , huffmancode * hc);

void savehuffman(huffman * root , fileutils * file);

void compress(huffmancode * hc , fileutils * file , huffman * root);


#endif
