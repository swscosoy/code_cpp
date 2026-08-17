// 引用 及 const
#include <iostream>

using namespace std;

int main()
{
    int a = 1;
    int & b = a;
    const int & m1 = b;
    // int & g = m1;
    // m1 = 2;
    b = 3;
    const int &c = 0;
    // cout << m1 << endl;
    
    // int *p1;
    // const int *const p3 = &a;
    // p1 = p3;

    // const int d = 1;
    // a = d;

    const int &e = a;
    const int f = a;
    a = 3;

    cout << f << endl;

    return 0;
}