#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <sstream>
using namespace std;
class Complex {
private:
    double r,i;
public:
    void Print() {
        cout << r << "+" << i << "i" << endl;
    }
// 在此处补充你的代码
    Complex& operator=(char* str) {
        char* end;
        r = strtod(str, &end);
        if (*end == '+') {
            i = strtod(end + 1, &end);
        } else {
            i = 0;
        }
        return *this;
    }
};
int main() {
    Complex a;
    a = "3+4i"; a.Print();
    a = "5+6i"; a.Print();
    return 0;
}