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

void inorder(huffman * root){
    if(root == NULL) return;
    inorder(root->left);
    printf("%d " , root->val);
    inorder(root->right);
}

void generatecodes(huffman * root, char* path) {
    if(root == NULL) return ;
}