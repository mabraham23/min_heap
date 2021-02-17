#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

#include <vector>

struct Element {
    int id;
    int key;
}; 

class BinaryHeap
{
private:
    int mSize;
    int mCapacity;
    std::vector<int> mIDs;
    std::vector<int> mKeys;
    std::vector<int> mIndices;

    int minIndex(int a, int b);
    int Parent( int i );
    int Left( int i );
    int Right( int i );

public:
    BinaryHeap(std::vector<Element> elements);
    ~BinaryHeap();
    void bubbleUp( Element x, int i );
    void siftDown( Element x, int i );
    void Insert( Element x );
    void decreaseKey( int id );
    int deleteMin();
    int minChild( int i );
    int Index( int ID );
    int getSize();

    friend std::ostream& operator<<(std::ostream& out, const BinaryHeap& heap);
};

int min( int a, int b );


#endif // BINARY_HEAP_H