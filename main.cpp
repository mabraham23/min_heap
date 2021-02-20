#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <fstream>
#include "binary_heap.h"
#include "math.h"

void testBinaryHeap() {
    srand (time(NULL));
    std::ofstream myfile("binary_heap.csv");

    for ( int i=1; i<29; i++ ){
        int heap_reps = 3;
        int utility_reps = 1;
        int heap_size = pow(2, i);
        double makeHeapAvg, deleteMinAvg, insertAvg, decreaseKeyAvg; 
        for ( int j=0; j<heap_reps; j++ ){
            std::vector<Element> test_heap(heap_size);
            for( int z=0; z<heap_size; z++){
                test_heap[z] = Element{ z, (rand() % 100) -100};
            }

            // Make Heap
            double t1, t2, dt;
            t1 = clock();
            BinaryHeap heap(test_heap);
            t2 = clock();
            dt = t2 - t1;
            makeHeapAvg += ( dt / CLOCKS_PER_SEC);


            for ( int r=0; r< utility_reps; r++ ) {
                
                // Delete Min
                t1 = clock();
                heap.deleteMin();
                t2 = clock();
                dt = t1 - t2;
                deleteMinAvg += (dt / CLOCKS_PER_SEC);

                // Insert
                t1 = clock();
                heap.Insert(Element{ heap_size +1, 100 });
                t2 = clock();
                dt = t2 - t1;
                insertAvg += ( dt / CLOCKS_PER_SEC);

                // Decrease Key
                t1 = clock();
                heap.decreaseKey( heap_size / 2, test_heap[ heap_size / 2 ].key -10 );
                t2 = clock();
                dt = t2 - t1;
                decreaseKeyAvg += ( dt / CLOCKS_PER_SEC );

            }

        }
        std::ostringstream ss;
        ss << i << ", ";
        ss << makeHeapAvg / heap_reps << ", ";
        ss << deleteMinAvg / ( heap_reps * utility_reps ) << ", ";
        ss << insertAvg / ( heap_reps * utility_reps ) << ", ";
        ss << decreaseKeyAvg / ( heap_reps * utility_reps ) << ", ";

        std::cout << ss.str() << std::endl;
        myfile << ss.str() << "\n";
    }
    myfile.close();
}


void test() {
    std::vector<int> ids {4, 7, 1, 2, 8, 3, 5, 6};
    std::vector<int> keys {11, 13, 13, 14, 12, 13, 13, 12};
    std::vector<Element> something {};

    for ( int i=0; i<keys.size(); i++){
        something.push_back(Element{ ids[i], keys[i]});
    }
    BinaryHeap H(something);
    std::cout << H << std::endl;
}

int main( int argc, char const* argv[]) {
    testBinaryHeap();
    // test();
    return 0;
}