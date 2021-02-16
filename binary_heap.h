#include "stdlib.h"
#include <iostream>
#include <vector>
#include <array>


class BinaryHeap
{
private:
    struct element {
        int size;
        int key;
    };
    std::vector<element> heap;

public:
    BinaryHeap();
    BinaryHeap(int size);
    int minChild( int i );
    int minIndex( int a, int b );
    void bubbleUp( element x, int i );
    void siftdown( element x, int i );
    void insert( element x );
    void decreasekey( element x );
    element deletemin();
    std::vector<element> makeheap( int S[] );
};