#include <iostream>
#include "binary_heap.h"


BinaryHeap::BinaryHeap(std::vector<Element> elements ){
    mCapacity = elements.size();
    mSize = elements.size();
    mIDs = std::vector<int>(mCapacity); 
    mKeys = std::vector<int>(mCapacity); 
    mIndices = std::vector<int>(mCapacity); 

    for( int i=0; i<elements.size(); i++ ){
        mIDs[i] = elements[i].id;
        mKeys[i] = elements[i].key;
        mIndices[elements[i].id] = i;
    }

    for( int i=mCapacity-1; i >= 0; i-- ){
        Element x{mIDs[i], mKeys[i]};
        this->siftDown( x, i);
    }
}

BinaryHeap::~BinaryHeap() {}

// place element x in position i of h, and let it sift down
void BinaryHeap::siftDown( Element x, int i ){
    int c = minChild(i);
    while( c > 0 && mKeys[c] < x.key ) {
        int c_ind = mIDs[c];
        mIDs[i] = c_ind;
        mKeys[i] = mKeys[c];
        mIndices[c_ind] = i;
        i = c;
        c = minChild(i);
    }
    mIDs[i] = x.id;
    mKeys[i] = x.key;
    mIndices[x.id] = i;
}

// place element x in position i of the binary heap, and let it bubble up 
void BinaryHeap::bubbleUp( Element x, int i ){
    int p = Parent(i);
    while ( i > 0 && mKeys[p] > x.key ){
        int p_ind = mIDs[p];
        mIDs[i] = p_ind;
        mKeys[i] = mKeys[p];
        mIndices[p_ind] = i;
        i = p;
        p = Parent(i);
    }
    mIDs[i] = x.id;
    mKeys[i] = x.key;
    mIndices[x.id] = i;
}

// return the index of the smalles child of a particular node in the binary heap
int BinaryHeap::minChild( int i ){
    if ( (2*i+1) < this->mSize ){
        return minIndex(Left(i), min(this->mSize -1, Right(i)));
    }
    return 0;
}

void BinaryHeap::Insert( Element x ){
    if ( mSize == mCapacity ) {
        std::cout << "Heap has reached its capacity " << std::endl; 
        return;
    }
    mSize++;
    bubbleUp( x, mSize-1);
}

void BinaryHeap::decreaseKey( int id ){
    int i = Index(id);
    this->bubbleUp(Element{ this->mIDs[i], this->mKeys[i] }, i);
}

// given two indecies in the heap, return the smalles one
int BinaryHeap::minIndex( int a, int b ){
    return this->mKeys[a] < this->mKeys[b] ? a : b;
}

int BinaryHeap::Index( int id ) {
    if ( id > mCapacity ) {
        return mIndices[id];
    }
    return -1;
}

int BinaryHeap::deleteMin( ){
    if ( mSize != 0 ) {
        Element el = Element{ mIDs[0], mKeys[0]};
        mSize--;
        siftDown(Element{ mIDs[mSize], mKeys[mSize]}, 0);
        return el.id;
    }
    // Else the heap is empty
    std::cout << "heap is emptpy, cannot delete" <<std::endl;
    return -1;
}

int BinaryHeap::Parent( int i ) {
    return ( i - 1 ) / 2;
}

int BinaryHeap::Left( int i ){
    return ( 2 * i + 1 );
}

int BinaryHeap::Right( int i ){
    return ( 2 * i + 2 );
}

int BinaryHeap::getSize(){
    return mSize;
}

int min( int a, int b ){
    return a < b ? a : b;
}


std::ostream& operator<<( std::ostream& out, const BinaryHeap& heap ){
    for( int i=0; i < heap.mSize; i++ ){
        out << heap.mIDs[i] << " ";
    }
    out << std::endl;
    for( int i=0; i < heap.mSize; i++ ){
        out << heap.mKeys[i] << " ";
    }
    out << std::endl;
    for( int i=0; i < heap.mSize; i++ ){
        out << heap.mIndices[i] << " ";
    }
    out << std::endl;
    for( int i=0; i < heap.mSize; i++ ){
        out << i << " ";
    }
    out << std::endl;
    return out;
}
