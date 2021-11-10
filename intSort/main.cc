#include "intArray.h"
#include "intSort.h"

int main(int argc, char **argv){
    IntArray a(1000);
    a.randomize();
    mergeSort(a, false);
    a.print();
    //insertSort(a, false);
    return 0;
}