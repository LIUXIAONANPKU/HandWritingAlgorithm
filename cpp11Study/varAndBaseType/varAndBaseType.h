#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

template <typename T>
void baseTypeExample(const string &typ, const string &varname, const T &var){
    cout << "type [" << typ << "] example:" << endl;
    cout << typ << " " << varname << " == " << var << endl;
    cout << "sizeof " << varname << " == " << sizeof(var) << endl;
}