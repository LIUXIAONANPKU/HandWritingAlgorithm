#include "varAndBaseType.h"

void listInit(){
    int a = 0;
    int b = {0};
    int c{0};
    int d(0);

    long double ld = 3.1415926536;
    //int e{ld};  // compiler warning: lost precision
    int e(ld);
    //int f = {ld};  // compiler warning: lost precisions
    int f = ld;
}

constexpr int size(int i){
    const int x = 10 + i;
    return x;
}

void constUsage(){
    const int ci = 1024;
    const int &r1 = ci;

    //r1 = 42;
    //int &r2 = ci;

    int i = 42;
    const int &r2 = i;
    const int &r3 = r1 * 2;
    //int &r4 = r1 * 2;
    double dval = 3.14;
    const int &r5 = dval;
    int ival = dval;
    int &r6 = ival;

    constexpr int mf = 20;
    constexpr int limit = mf + 1;
    const int r8 = mf + 1;
    constexpr int sz = size(3);
    
}

int main(){
    constUsage();
    listInit();
    bool a = false;
    baseTypeExample("bool", "a", a);

    wchar_t b = L'H';
    baseTypeExample("w_char", "b", b);

    char c = 'H';
    baseTypeExample("char", "c", c);

    char16_t d = 'H';
    baseTypeExample("char16_t", "d", d);

    char32_t e = 'H';
    baseTypeExample("char32_t", "e", e);

    baseTypeExample("string u8", "u8Hi", u8"Hi");
    baseTypeExample("42ULL", "42ULL", 42ULL);
    baseTypeExample("42UL", "42UL", 42UL);
    baseTypeExample("42L", "42L", 42L);
    baseTypeExample("1E-3F", "1E-3F", 1E-3F);
    baseTypeExample("3.14159L", "3.14159L", 3.14159L);

    char *p = nullptr;
    //baseTypeExample("null ptr", "p", p);
    return 0;
}