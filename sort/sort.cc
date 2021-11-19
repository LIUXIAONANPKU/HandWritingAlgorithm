#include <algorithm>
#include "Uheap.h"
#include "sort.h"

void max_heap_ify(Uheap &a, index_t i);
void build_max_heap(Uheap &a);

void heap_sort(Uheap &a){
    build_max_heap(a);
    for(int i = a.length - 1; i >= 1; --i){
        std::swap(a[0], a[i]);
        a.heapSize--;
        max_heap_ify(a, 0);
    }
}

void max_heap_ify(Uheap &a, index_t i){
    index_t ll = left(i);
    index_t rr = right(i);
    index_t largest;
    if(ll < a.heapSize && a[ll] > a[i])
        largest = ll;
    else
        largest = i;
    if(rr < a.heapSize && a[rr] > a[largest]){
        largest = rr;
    }
    if(largest != i){
        std::swap(a[i], a[largest]);
        max_heap_ify(a, largest);
    }
}

void build_max_heap(Uheap &a){
    a.heapSize = a.length;
    for(int i = (a.length >> 1) - 1; i >= 0; --i){
        max_heap_ify(a, i);
    }
}



