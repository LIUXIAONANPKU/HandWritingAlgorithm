#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include <time.h>
#include <chrono>
#include "intArray.h"
#include "console.h"

IntArray& IntArray::operator=(const IntArray& rhs){
    if(this == &rhs){
        return *this;
    }
    if(_size != 0){
        delete [] ap;
    }
    init(rhs);
    return *this;
}

void IntArray::randomize(){
    srand((unsigned)time(NULL));
    for(int i = 0; i < _size; i++){
        int random_num = rand() % 50 - 25;
        ap[i] = random_num;
    }
}

void IntArray::swap(int left, int right){
    int temp;
    temp = ap[left];
    ap[left] = ap[right];
    ap[right] = temp;
}

void IntArray::print(){
    std::cout << "Int array is:" << std::endl;
    const int lineLen = 10;
    int lineLeft = lineLen;
    for(int i = 0; i < _size; i++){
        std::cout << ap[i] << '\t';
        lineLeft--;
        if(lineLeft == 0){
            std::cout << std::endl;
            lineLeft = lineLen;
        }
    }
}

void IntArray::plot(){
    const int twinkle_time = int(0.5 * 1000000);
    usleep(twinkle_time);
    CLEAR();
    RESET_CURSOR();
    for(int i = 0; i < _size; i++){
        for(int j = 0; j < ap[i]; j++){
            std::cout << '*';
        }
        std::cout << std::endl;
    }
}

const IntArray IntArray::part(int left, int right){
    IntArray a(right - left, ap + left);
    return a;
}

void IntArray::init(int sz, int *array){
    _size = sz;
    ap = new int[_size];
    if(!array){
        for(int i = 0; i < _size; i++){
            ap[i] = 0;
        }
        return;
    }
    for(int i = 0; i < _size; i++){
        ap[i] = array[i];
    }
}

void IntArray::init(const IntArray &rhs){
    _size = rhs.size();
    if(_size == 0){
        return;
    }
    ap = new int[_size];
    for(int i = 0; i < _size; i++){
        ap[i] = rhs[i];
    }
}
