#include"../include/minheap.h"

void createheap(minheap * heap){
    heap->size = 0;
}

void heapinsert(minheap * heap , huffman * node){
    int i = heap->size++;
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap->data[parent]->freq <= node->freq) break;
        heap->data[i] = heap->data[parent];
        i = parent;
    }
    heap->data[i] = node;
}

huffman * heapextractmin(minheap * heap){
    if (heap->size == 0) return NULL;

    huffman *min = heap->data[0];
    huffman *last = heap->data[--heap->size];

    int i = 0;
    while (i * 2 + 1 < heap->size) {
        int left = i * 2 + 1;
        int right = left + 1;
        int smallest = left;

        if (right < heap->size && heap->data[right]->freq < heap->data[left]->freq)
            smallest = right;

        if (last->freq <= heap->data[smallest]->freq) break;

        heap->data[i] = heap->data[smallest];
        i = smallest;
    }
    heap->data[i] = last;
    return min;
}