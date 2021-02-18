#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <fstream>
#include "binary_heap.h"


void testBinaryHeap() {
    // vector to hold element objects for creating the heap
    std::vector<Element> test{};

    // values for id and key
    std::vector<int> ids{ 4, 7, 3, 8, 0, 1, 6, 2, 5 };
    std::vector<int> keys{ 22, 27, 34, 21, 18, 44, 40, 23, 28 };

    // fill the test vector
    for ( int i=0; i<keys.size(); i++){
        test.push_back(Element{ ids[i], keys[i]});
    }

    // Inialize binary heap with test data
    BinaryHeap heap(test);

    // output the heaps values    
    std::cout << heap << std::endl;
}

int main( int argc, char const* argv[]) {
    testBinaryHeap();
    
    return 0;
}