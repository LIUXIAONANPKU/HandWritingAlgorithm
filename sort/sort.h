#ifndef SORT_H
#define SORT_H

#include "Uheap.h"

inline index_t parent(index_t i){
    return i % 2 ? i >> 1 : (i >> 1) - 1;
}

inline index_t left(index_t i){
    return (i << 1) + 1;
}

inline index_t right(index_t i){
    return (i << 1) + 2;
}

void heap_sort(Uheap &a);


#endif