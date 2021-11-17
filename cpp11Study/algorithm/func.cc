#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <array>
#include <string>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

void use_find(){
    int val = 42;
    vector<int> v = {1, 2, 42 ,3, 5,8};
    auto result = find(v.cbegin(), v.cend(), val);
    cout << "The value " << val
         << (result == v.cend() ? " is not present" : " is present") << endl;

    int ia[] = {1 ,2 ,3,4,5, 9,7};
    int val1 = 3;
    int res = accumulate(begin(ia), end(ia), 0);
    cout << "sum value " << res << endl;
    
}