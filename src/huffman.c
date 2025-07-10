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

void generatehuffmancodes(huffman * root, int path[] , int pathlength ,huffmancode * hc) {
    if (root == NULL) return;
    hc->nodes++;
    if (root->left == NULL && root->right == NULL) {
        unsigned long long bincode = 0;
        for (int i = 0; i < pathlength; i++) {
            bincode <<= 1;
            if(path[i]) bincode |= 1;
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

void savehuffman(huffman * root , fileutils * file){
    if(root == NULL) return;
    savehuffman(root->left , file);
    savehuffman(root->right , file);
    if(root->left == NULL && root->right == NULL){
        unsigned char marker = 1;
        fwrite(&marker , 1 , 1 , file->outputfile);
        fwrite(&(root->val) , 1 , 1 , file->outputfile);
    }
    else{
        unsigned char marker = 0;
        fwrite(&marker , 1 , 1 , file->outputfile);
    }
}

void compress(huffmancode * hc , fileutils * file , huffman * root){
    const char* sign = "psy";
    fwrite(sign , sizeof(const char) , 1 , file->outputfile);
    fwrite(&hc->nodes , sizeof(unsigned int) , 1 , file->outputfile);
    savehuffman(root , file);
    unsigned char bitbuffer = 0;
    int bitcount = 0;
    for(int i = 0; i < 256;++i){
        if(hc->codelength[i]){
            unsigned long long code = hc->code[i];
            unsigned int length = hc->codelength[i];
            for(int i = length -  1; i >= 0; i--){
                int bit = (code >> i) & 1;
                bitbuffer = (bitbuffer << 1) | bit;
                bitcount++;
                if(bitcount == 8){
                    fputc(bitbuffer , file->outputfile);
                    bitbuffer = 0;
                    bitcount = 0;
                }
            }
        }
    }
    if(bitcount > 0){
        bitbuffer <<= (8 - bitcount);
        fputc(bitbuffer , file->outputfile);
    }
}