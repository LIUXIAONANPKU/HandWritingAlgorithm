#include <iostream>
#include <vector>

using namespace std;

extern void ioObjNoCopy();
extern void ioState();
extern void ioFlash();
extern void ioFile();

int main(){
    
    cout << "Hello world!" << endl;
    ioObjNoCopy();
    ioState();
    ioFlash();
    ioFile();
    return 0;
}