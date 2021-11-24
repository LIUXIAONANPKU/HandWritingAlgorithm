#include <vector>
#include <iostream>
#include <random>
#include <algorithm>

#include "UIntArray.h"

UIntArray::UIntArray(int size):a(std::vector<int>(size)){
    std::uniform_int_distribution<int> u(-200, 200);
    std::default_random_engine e;
    for(int i = 0; i < size; ++i)
        a[i] = u(e);
}

UIntArray::UIntArray(std::vector<int> &v){
    for(auto c = v.cbegin(); c != v.cend(); ++c)
        a.push_back(*c);
}

int &UIntArray::operator[](int i){
    return a[i];
}

std::ostream &operator<<(std::ostream &os, UIntArray &ia){
    std::cout << "{";
    for(auto c = ia.a.cbegin(); c != ia.a.cend(); ++c)
        std::cout << *c << ",";
    std::cout << "\b }" << std::endl;
}

bool UIntArray::isSorted(){
    if(a.size() <= 1)
        return true;
    for(auto c = a.cbegin() + 1; c != a.cend(); ++c){
        if(*(c - 1) > *c)
            return false;
    }
    return true;
}

void UIntArray::sort(){
    std::sort(a.begin(), a.end());
}