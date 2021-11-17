#include "maxSubArray.h"
#include "intArray.h"

maxSubArray findMaxCrossSubArray(const IntArray &a, int low, int mid, int high);

maxSubArray findMaxCrossSubArray(const IntArray &a, int low, int mid, int high){
    int leftSum = -1000;
    int rightSum = mid == high ? 0 : -1000;
    int sum = 0;
    int maxLeft = mid;
    int maxRight = mid;
    for(int i = mid; i >= low; i--){
        sum += a[i];
        if(sum > leftSum){
            leftSum = sum;
            maxLeft = i;
        }
    }
    sum = 0;
    for(int i = mid + 1; i <= high; i++){
        sum += a[i];
        if(sum > rightSum){
            rightSum = sum;
            maxRight = i;
        }
    }
    return maxSubArray(maxLeft, maxRight, leftSum + rightSum);
}

maxSubArray divideFindMaxSubArray(const IntArray &a, int left, int right){
    if(right == left){
        return maxSubArray(left, right, a[left]);
    }
    else{
        int mid = (left + right) / 2;
        maxSubArray leftSubArray = divideFindMaxSubArray(a, left, mid);
        maxSubArray rightSubArray = divideFindMaxSubArray(a, mid + 1, right);
        maxSubArray crossSubArray = findMaxCrossSubArray(a, left, mid, right);
        if(leftSubArray.maxSum >= rightSubArray.maxSum && \
                leftSubArray.maxSum >= crossSubArray.maxSum){
            return leftSubArray;
        }
        else if(rightSubArray.maxSum >= leftSubArray.maxSum && \
                rightSubArray.maxSum >= crossSubArray.maxSum){
            return rightSubArray;
        }
        else{
            return crossSubArray;
        }
    }
}

maxSubArray violentFindMaxSubArray(const IntArray & a, int left, int right){
    maxSubArray sa(left, left, a[left]);
    for(int i = left; i <= right; i++){
        int sum = a[i];
        for(int j = i + 1; j <= right; j++){
            if(sum > sa.maxSum){
                sa.low = i;
                sa.high = j;
                sa.maxSum = sum;
            }
            sum += a[j];
        }
    }
    return sa;
}