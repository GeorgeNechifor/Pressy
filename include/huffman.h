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

huffman * createnode(unsigned int freq , unsigned char val , huffman * l , huffman * r);

void destroy(huffman * root);

void inorder(huffman * root);

void generatecodes(huffman * root , char* path);

#endif
