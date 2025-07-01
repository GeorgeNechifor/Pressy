#include"../include/huffman.h"

huffman * createnode(unsigned int freq , unsigned char val){
    huffman * node = (huffman*)malloc(sizeof(huffman));
    if(!node){
        perror("Memory allocation failed!");
        exit(EXIT_FAILURE);
    }
    node->val = val;
    node->freq = freq;
    node->left = NULL;
    node->right = NULL;
    return node;
}

huffman * insert(unsigned int freq , unsigned char val , huffman * root){
    if(root == NULL){
        return createnode(freq , val);

    }
    if(freq < root->freq)
        root->left = insert(freq , val , root->left);
    else
        root->right = insert(freq , val , root->right);
    return root;
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
    printf("%d " , root->freq);
    inorder(root->right);
}