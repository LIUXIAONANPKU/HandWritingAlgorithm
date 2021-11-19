#include <iostream>
#include <vector>
#include <random>
#include "sort.h"

using std::cout;
using std::endl;
using std::vector;
using std::default_random_engine;
using std::uniform_int_distribution;

int main(int argc, char **argv){
    std::cout << "Hello Heap Sort." << std::endl;
    const int size = 20;
    const int test_time = 1;
    vector<int> intArray(size);
    uniform_int_distribution<int> u(-200, 200);

    for(int j = 0; j < test_time; ++j){
        default_random_engine e(j);
        for(int i = 0; i < size; ++i){
            intArray[i] = u(e);
        }
        Uheap h(intArray);
        cout << "heap is " << (h.isSorted() ? "sorted " : "not sorted ") << endl;
        cout << h;
        heap_sort(h);
        cout << "After sort. Heap is " << (h.isSorted() ? "sorted " : "not sorted ") << endl;
        cout << h;
    }
    
    return 0;
}