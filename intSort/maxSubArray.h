#ifndef MAX_SUB_ARRAY_H
#define MAX_SUB_ARRAY_H
#include <iostream>

#include "intArray.h"
using std::cout;
using std::endl;

class maxSubArray{
public:
    int low;
    int high;
    int maxSum;

    maxSubArray(){
        low = -1;
        high = -1;
        maxSum = 0;
    }
    maxSubArray(int l, int h, int s){
        low = l;
        high = h;
        maxSum = s;
    }
    ~maxSubArray(){}

    void print(){
        cout << "max sub array:" << endl;
        cout << "low bound = " << low << endl;
        cout << "high bound = " << high << endl;
        cout << "max sum = " << maxSum << endl;
    }
};

maxSubArray divideFindMaxSubArray(const IntArray & a, int left, int right);
maxSubArray linearFindMaxSubArray(const IntArray & a, int left, int right);
maxSubArray violentFindMaxSubArray(const IntArray & a, int left, int right);



#endif