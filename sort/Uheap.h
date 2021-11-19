#ifndef UHEAP_H
#define UHEAP_H

#include <vector>
#include <iostream>

using index_t = std::vector<int>::size_type;
using size_t = std::vector<int>::size_type;

class Uheap{

private:
    std::vector<int> uarray;

public:
    size_t length;
    size_t heapSize;

    Uheap(std::vector<int> &v){
        length = heapSize = v.size();
        uarray = v;
    }

    int &operator[](index_t i){ return uarray[i]; }
    friend std::ostream &operator<<(std::ostream &os, const Uheap &h);

    bool isSorted();
};


#endif