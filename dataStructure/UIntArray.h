#ifndef UINTARRAY_H
#define UINTARRAY_H

#include <iostream>
#include <vector>

class UIntArray{

  private:
    static const int csize = 100;
    std::vector<int> a;

  public:
    UIntArray(int size = csize);
    UIntArray(std::vector<int> &v);
    ~UIntArray(){};

    
    int &operator[](int i);
    friend std::ostream &operator<<(std::ostream &os, UIntArray &ia);

    bool isSorted();
    void sort();

};

#endif /* UINTARRAY_H */