#include <memory>
#include <iostream>

using namespace std;

void use_shared_ptr(){
    shared_ptr<string> p1 = make_shared<string>();

    if(p1 && p1->empty())
        *p1 = "hi";
        cout << *p1 << endl;
}

