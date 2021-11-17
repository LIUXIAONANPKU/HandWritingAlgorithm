#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <array>
#include <string>
#include <iostream>

using namespace std;

template <typename T>
void show_serial(const string &tpname, T &s){
    cout << tpname << " type serial is:" << endl;
    for(auto e : s){
        cout << e << " ";
    }
    cout << endl;
}


void serialExample(){
    vector<int> a = {1 ,2, 3, 5 ,4 , 6 };
    show_serial("vector<int>", a);
    deque<int> b = {1 ,2, 3, 5 ,4 , 6 };
    show_serial("deque<int>", b);
    list<int> c = {1 ,2, 3, 5 ,4 , 6 };
    show_serial("list<int>", c);
    forward_list<int> d = {1 ,2, 3, 5 ,4 , 6 };
    show_serial("forword_list<int>", d);
    array<int, 6> e = {1,2 ,3,4,5,6};
    show_serial("array<int>", e);
    string f = "{1, 2, 3, 4, 5, 6}";
    show_serial("string", f);
}

void container_ops(){
    vector<int> a = {1 ,2, 3, 5 ,4 , 6 };
    for(auto it = a.cbegin(); it != a.cend(); ++it){
        *it;
    }
    show_serial("vector<int>", a);
    for(auto it = a.crbegin(); it != a.rend(); ++it){
        cout << *it << " ";
    }
    cout << endl;

    vector<int> b;
    b.push_back(3);
    b.push_back(5);
    show_serial("b = ", b);

    vector<int> c(b);
    show_serial("c = ", c);

    vector<int> d(a.cbegin(), a.cend() - 3);
    show_serial("d = ", d);

    cout << "size of d is: " << d.size()<< endl;
    cout << "max size of d is: " << d.max_size()<< endl;
    cout << "capacity of d is: " << d.capacity()<< endl;
    d.push_back(100);
    cout << "capacity of d is: " << d.capacity()<< endl;
    show_serial("d = ", d);
    swap(d[1], d[2]);
    show_serial("d = ", d);

    vector<int> seq1(10, 66);
    show_serial("seq1 =", seq1);
    vector<int> seq2(10, 77);
    show_serial("seq2 =", seq2);
    swap(seq1, seq2);
    show_serial("seq1 =", seq1);
    show_serial("seq2 =", seq2);
    *(d.begin());


    cout << endl;
}