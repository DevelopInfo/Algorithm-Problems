#include <iostream>
#include <string>
using namespace std;

int main(){
    int a[1000000];
    long long b = 1;
    cout << sizeof(a) << endl;
    cout << sizeof(short) << endl;
    cout << sizeof(int) << endl;
    cout << sizeof(long) << endl;
    cout << sizeof(b) << endl;

    string s = "abc";
    const char* c1 = s.c_str();
    cout << "*c1: " << *c1 << endl;
    const char* c2 = s.data();
    cout << "*c3: " << *c2 << endl;
    char c3[4];
    s.copy(c3, 3, 0);
    *(c3+3) = '\0';
    cout << "*c3: " << *c3 << endl;
    cout << "*c3: " << c3 << endl;
}