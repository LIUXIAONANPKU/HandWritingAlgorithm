#include <iostream>
#include <vector>

using namespace std;

extern void use_shared_ptr();

int main(){
    
    cout << "Hello world!" << endl;
    use_shared_ptr();
    return 0;
}