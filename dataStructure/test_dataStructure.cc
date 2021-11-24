#include <iostream>
#include <cassert>
#include "UIntArray.h"

int main(int argc, char **argv){
    std::cout << "data structure test." << std::endl;
    UIntArray ia;
    std::cout << ia;
    assert(!ia.isSorted());
    ia.sort();
    std::cout << ia;
    assert(ia.isSorted());
    std::cout << "data structure test finished." << std::endl;
}