#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cstdlib>
using namespace std;

class Student {
    string in;
    string name; // 姓名
    int age; // 年龄
    string number; // 学号
    double score[4]; // 平均成绩
    string step;
    double sum = 0;

public:
    void input() {
        getline(cin, in);
        stringstream ss(in);

        getline(ss, name, ',');

        getline(ss, step, ',');
        age = stoi(step);

        getline(ss, number, ',');

        for (int i = 0; i < 4; i++) {
            getline(ss, step, ',');
            score[i] = stod(step);
            // cout << score[i] << endl;
        }
    }

    void calculate() {

        for (int i = 0; i < 4; i++) {
            sum += score[i];
            // cout << sum << endl;
        }
        // cout << sum << endl;
        sum = sum / 4;
    }

    void output() {
        cout << name << "," << age << "," << number << "," << sum;
    }
        
// 在此处补充你的代码
};

int main() {
	Student student;        // 定义类的对象
	student.input();        // 输入数据
	student.calculate();    // 计算平均成绩
	student.output();       // 输出数据
}