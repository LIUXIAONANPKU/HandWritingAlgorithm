#include <iostream>
#include "Uheap.h"

bool Uheap::isSorted(){
    if(uarray.size() <= 1)
        return true;
    for(auto x = uarray.cbegin(); x != uarray.cend() - 1; ++x){
        if(*x > *(x + 1))
            return false;
    }
    return true;
}



std::ostream &operator<<(std::ostream &os, const Uheap &h){
    for(auto c = h.uarray.cbegin(); c != h.uarray.cend(); ++c){
        std::cout << *c << " ";
    }
    std::cout << std::endl;
}