#include <iostream>
#include <vector>
#include <random>
#include "maxSubArray.h"

using std::cout;
using std::endl;
using std::vector;
using std::default_random_engine;
using std::uniform_int_distribution;

int main(int argc, char **argv){
    std::cout << "Hello max sub array." << std::endl;
    const int size = 200;
    const int test_time = 100000;
    vector<int> intArray(size);
    uniform_int_distribution<int> u(-200, 200);

    int sumEqualTimes = 0;
    int boundEqualTimes = 0;

    for(int j = 0; j < test_time; ++j){
        default_random_engine e(j);
        for(int i = 0; i < size; ++i){
            intArray[i] = u(e);
        }
        MaxSubArray violateRes = violateFind(intArray);
        MaxSubArray divideRes = divideFind(intArray);
        MaxSubArray linearRes = linearFind(intArray);
        if(violateRes.maxSum == divideRes.maxSum && violateRes.maxSum == linearRes.maxSum)
            sumEqualTimes++;
        if(violateRes.low == divideRes.low && violateRes.high == divideRes.high &&
            violateRes.low == linearRes.low && violateRes.high == linearRes.high)
            boundEqualTimes++;
    }
    cout << "max sum equal times = " << sumEqualTimes << endl;
    cout << "max sum unequal times = " << test_time - sumEqualTimes << endl;
    cout << "bound equal times = " << boundEqualTimes << endl;
    cout << "bound unequal times = " << test_time - boundEqualTimes << endl;
    return 0;
}