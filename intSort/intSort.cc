#include "intArray.h"
#include <iostream>
#include <chrono>



void insertSort(IntArray &a, bool ifPlot){
    auto start = std::chrono::high_resolution_clock::now();
    int size = a.size();
    for(int i = 0; i < size; i++){
        for(int j = i; j > 0; j--){
            if(a[j] < a[j - 1]){
                a.swap(j - 1, j);
                if(ifPlot) a.plot();
            }
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> tm = end - start;
    std::cout << "insert sort time = " << tm.count() << "ms" << std::endl;
}

void merge(IntArray &a, int left, int right, int middle, bool ifPlot){
    if(!(middle > left && right > middle)){
        return;
    }
    IntArray La = a.part(left, middle);
    IntArray Ra = a.part(middle, right);
    int indexLeft = 0;
    int indexRight = 0;
    for(int i = left; i < right; i++){
        if(indexLeft < La.size()){
            if(indexRight < Ra.size()){
                if(La[indexLeft] < Ra[indexRight]){
                    a[i] = La[indexLeft];
                    indexLeft++;
                } else{
                    a[i] = Ra[indexRight];
                    indexRight++;
                }
            } else{
                a[i] = La[indexLeft];
                indexLeft++;
            }
        } else{
            if(indexRight < Ra.size()){
                a[i] = Ra[indexRight];
                indexRight++;
            }
        }
        if(ifPlot) a.plot();
    }
    
}

void mergeSortPart(IntArray &a, int left, int right, bool ifPlot){
    int length = right - left;
    if(length <= 1) return;
    int middle = left + length / 2;
    mergeSortPart(a, left, middle, ifPlot);
    mergeSortPart(a, middle, right, ifPlot);
    merge(a, left, right, middle, ifPlot);
}

void mergeSort(IntArray &a, bool ifPlot){
    auto start = std::chrono::high_resolution_clock::now();
    mergeSortPart(a, 0, a.size(), ifPlot);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> tm = end - start;
    std::cout << "merge sort time = " << tm.count() << "ms" << std::endl;
}

