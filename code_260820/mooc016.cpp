#include <iostream>
using namespace std;
class Point
{
private:
    int x;
    int y;

public:
    Point() {};
    // 在此处补充你的代码
    friend istream &operator>>(istream &cin, Point &s);
    friend ostream &operator<<(ostream &cout, Point &s);
};

ostream &operator<<(ostream &cout, Point &s)
{
    cout << s.x << "," << s.y;
    return cout;
};

istream &operator>>(istream &cin, Point &s)
{
    cin >> s.x >> s.y;
    return cin;
};
int main()
{
    Point p;
    while (cin >> p)
    {
        cout << p << endl;
    }
    return 0;
}