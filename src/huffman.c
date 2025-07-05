#include"../include/huffman.h"

huffman * createnode(unsigned int freq , unsigned char val , huffman * l , huffman * r){
    huffman * node = (huffman*)malloc(sizeof(huffman));
    if(!node){
        perror("Memory allocation failed!");
        exit(EXIT_FAILURE);
    }
    node->val = val;
    node->freq = freq;
    node->left = l;
    node->right = r;
    return node;
}

void destroy(huffman * root){
    if(root){
        destroy(root->left);
        destroy(root->right);
        free(root);
    }
}

void concatbin(int bin , unsigned long long bincode) {
    bincode <<= 1;
    if (bin) bincode |= 1;
}
void generatehuffmancodes(huffman * root, int path[] , int pathlength ,huffmancode * hc) {
    if (root == NULL) return;

    if (root->left == NULL && root->right == NULL) {
        unsigned long long bincode = 0;
        for (int i = 0; i < pathlength; i++) {
            concatbin(path[i] , bincode);
        }
        hc->codelength[root->val] = pathlength;
        hc->code[root->val] = bincode;
    } else {
        path[pathlength] = 0;
        generatehuffmancodes(root->left, path, pathlength + 1 , hc);
        path[pathlength] = 1;
        generatehuffmancodes(root->right, path, pathlength + 1 , hc);
    }
}