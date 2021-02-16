#include "binary_heap.h"

BinaryHeap::BinaryHeap(){
}

BinaryHeap::BinaryHeap( int size ){
    this->element;
    this->heap;
}

// return the index of the smalles child of h[i]
int BinaryHeap::minChild( int i ){
    if ( 2 * i < this->size ){
        return minIndex(left(i), min(this->size -1, right(i)));
    }
    return 0;
}

// given two indecies in the heap, return the smalles one
int BinaryHeap::minIndex( int a, int b ){
    return this->heap[a] < this->heap[b] ? a : b;
}

int min( int a, int b ){
    return a < b ? a : b;
}

int left( int i ){
    return 2 * i + 1;
}

int right( int i ){
    return 2 * i + 2;
}

// place element x in position i of h, and let it bubble up 
void BinaryHeap::bubbleUp( element x, int i ){
    int p = i / 2;
    while ( i != 1 && this->heap[p].key > x.key ){
        this->heap[i] = this->heap[p];
        i = p;
        p = i / 2;
    }
    this->heap[i] = x;
}

// place element x in position i of h, and let it sift down
void BinaryHeap::siftdown( element x, int i ){
    int c = this->minChild(i);
    while ( c != 0 && this->heap[c].key < x.key ) {
        this->heap[i] = this->heap[c];
        i = c;
        c = this->minChild( i );
    }
    this->heap[i] = x;
}

void BinaryHeap::insert( element x ){
    this->bubbleUp( x, this->heap.size() + 1);
}

void BinaryHeap::decreasekey( element x ){
    this->bubbleUp( x, this->heap[x]);
}

element BinaryHeap::deletemin( ){
    if ( this->heap.size() == 0 ) {
        return NULL;
    }
    else{
        x = this->heap[1];
        this->siftdown(this.heap[this.heap.size()], 1);
        return x;
    }
}

std::vector<element> BinaryHeap::makeheap( int S[] ){
    int H[S.size()];
    for ( int i=0; i<S.size(); i++ ){
        this->heap[this->heap.size() +1] = x;
    }
    for ( int i = S.size(); i > 0; i--){
        this->siftdown(h[i], i);
    }
    return this->heap;
}
