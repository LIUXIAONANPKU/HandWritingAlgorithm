#include <vector>
#include <iostream>
#include <algorithm>

#include "maxSubArray.h"

using std::vector;
using std::ostream;
using std::cout;
using std::endl;

ostream &operator<<(ostream &os, const MaxSubArray &a){
    os << "Set of MaxSunArray:" << endl;
    os << "low index = " << a.low << endl;
    os << "hing index = " << a.high << endl;
    os << "max sum = " << a.maxSum << endl;
}

MaxSubArray violateFind(vector<int> &a){
    if(a.empty())
        return MaxSubArray();
    int size = a.size();
    int low, high;
    int maxSum = a[0];
    for(int i = 0; i < size; ++i){
        int sum = 0;
        for(int j = i; j < size; ++j){
            sum += a[j];
            if(sum > maxSum){
                maxSum = sum;
                low = i;
                high = j + 1;
            }
        }
    }
    return MaxSubArray(low, high, maxSum);
}

MaxSubArray findCrossMaxSub(vector<int> &a, int low, int mid, int high){
    int left_sum = a[mid - 1];
    int right_sum = a[mid];
    int max_left = mid - 1;
    int max_right = mid + 1;

    int sum = left_sum;
    for(int i = mid - 2; i >= low; --i){
        sum += a[i];
        if(sum > left_sum){
            left_sum = sum;
            max_left = i;
        }
    }
    sum = right_sum;
    for(int i = mid + 1; i < high; ++i){
        sum += a[i];
        if(sum > right_sum){
            right_sum = sum;
            max_right = i + 1;
        }
    }
    return MaxSubArray(max_left, max_right, left_sum + right_sum);
}

MaxSubArray divideFind(vector<int> &a, int low, int high){
    if(low == high - 1)
        return MaxSubArray(low, high, a[low]);
    else{
        int mid = (low + high) / 2;
        MaxSubArray leftSub = divideFind(a, low, mid);
        MaxSubArray rightSub = divideFind(a, mid, high);
        MaxSubArray crossSub = findCrossMaxSub(a, low, mid, high);
        if(leftSub.maxSum >= rightSub.maxSum && leftSub.maxSum >= crossSub.maxSum)
            return leftSub;
        else if(rightSub.maxSum >= leftSub.maxSum && rightSub.maxSum >= crossSub.maxSum)
            return rightSub;
        else
            return crossSub;
    }
}

MaxSubArray divideFind(vector<int> &a){
    if(a.empty())
        return MaxSubArray();
    return divideFind(a, 0, a.size());
}

MaxSubArray linearFind(vector<int> &a){
    if(a.empty())
        return MaxSubArray();
    int size = a.size();
    int low = 0;
    int high = 1;
    int rightMaxSum = a[0];
    int maxSum = a[0];
    for(int i = 1; i < size; i++){
        if(rightMaxSum < 0){
            rightMaxSum = a[i];
            if(rightMaxSum > maxSum){
                low = i;
                high = i + 1;
                maxSum = rightMaxSum;
            }
        }
        else{
            rightMaxSum += a[i];
            if(rightMaxSum > maxSum){
                high = i + 1;
                maxSum = rightMaxSum;
            }
        }
    }
    return MaxSubArray(low, high, maxSum);
}



