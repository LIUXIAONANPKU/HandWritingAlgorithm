#ifndef MAX_SUB_ARRAY_H
#define MAX_SUB_ARRAY_H

#include <iostream>
#include <vector>


class MaxSubArray{
    

public:
    int low;
    int high;
    int maxSum;

    MaxSubArray():low(-1), high(-1), maxSum(0){}
    MaxSubArray(int vlow, int vhigh, int vmaxsum):
        low(vlow), high(vhigh), maxSum(vmaxsum){}

    friend std::ostream &operator<<(std::ostream &os, const MaxSubArray &a);
    
};

MaxSubArray violateFind(std::vector<int> &a);
MaxSubArray divideFind(std::vector<int> &a);
MaxSubArray linearFind(std::vector<int> &a);


#endif