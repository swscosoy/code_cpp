#include <cstdlib>
#include <iostream>
using namespace std;
int strlen(const char *s)
{
    int i = 0;
    for (; s[i]; ++i)
        ;
    return i;
}
void strcpy(char *d, const char *s)
{
    int i = 0;
    for (i = 0; s[i]; ++i)
        d[i] = s[i];
    d[i] = 0;
}
int strcmp(const char *s1, const char *s2)
{
    for (int i = 0; s1[i] && s2[i]; ++i)
    {
        if (s1[i] < s2[i])
            return -1;
        else if (s1[i] > s2[i])
            return 1;
    }
    return 0;
}
void strcat(char *d, const char *s)
{
    int len = strlen(d);
    strcpy(d + len, s);
}
class MyString
{
    // 在此处补充你的代码

    // 运算符重载函数设为 友元
    friend ostream &operator<<(ostream &cout, MyString s);
    friend MyString operator+(const char *ss, MyString s);
    friend MyString operator+(MyString s, const char *ss);

private:
    char *p;

public:
    // 构造函数
    MyString(const char *ss)
    {
        if (ss)
        {
            p = new char[strlen(ss) + 1];
            strcpy(p, ss);
        }
        else
        {
            p = NULL;
        }
    }

    // 复制构造函数
    MyString(MyString &s)
    {
        if (s.p)
        {
            p = new char[strlen(s.p) + 1];
            strcpy(p, s.p);
        }
        else
        {
            p = NULL;
        }
    }

    // 默认构造函数
    MyString() : p(new char[1]) {
        p[0] = '\0';
    }

    // 析构函数
    ~MyString()
    {
        delete[] p;
        p = NULL;
    }

    // 加号运算符重载 类对象
    MyString operator+(const MyString &s)
    {
        char * buf = new char[strlen(this->p) + strlen(s.p) + 1];
        strcpy(buf, this->p);
        strcat(buf, s.p);       
        MyString temp(buf);
        delete [] buf;
        return temp;
    }

    // +=运算符重载2
    void operator+=(const char *ss)
    {
        char * buf = new char[strlen(this->p) + strlen(ss) + 1];
        strcpy(buf, this->p);
        strcat(buf, ss);
        MyString temp(buf);
        delete [] buf;
        *this = temp;
    }

    // =运算符重载1
    MyString &operator=(const MyString &s)
    {
        int len;
        if (strlen(this->p) > strlen(s.p))
            len = strlen(this->p);
        else
            len = strlen(s.p);
        delete[] p;
        p = new char[len + 1];
        strcpy(this->p, s.p);
        return *this;
    }

    // =运算符重载2
    MyString &operator=(const char *ss)
    {
        strcpy(this->p, ss);
        return *this;
    }

    // 数组元素运算符重载
    char &operator[](int a)
    {
        return this->p[a];
    }

    // >运算符重载
    bool operator>(MyString s)
    {
        if (strcmp(this->p, s.p) > 0)
            return true;
        else
            return false;
    }

    // <运算符重载
    bool operator<(MyString s)
    {
        if (strcmp(this->p, s.p) < 0)
            return true;
        else
            return false;
    }

    // ==运算符重载
    bool operator==(MyString s)
    {
        if (strcmp(this->p, s.p) == 0)
            return true;
        else
            return false;
    }

    // 函数重载
    MyString operator()(int n, int m)
    {
        MyString temp;
        temp.p = new char[ m+1 ];
        for (int i = 0; i < m; i++)
        {
            // cout << n+i << " " << this->p[n + i] << endl;
            temp.p[i] = this->p[n + i];
        }
        temp.p[m] = '\0';
        return temp;
    }
};

// 左移运算符重载
ostream &operator<<(ostream &cout, MyString s)
{
    if(s.p)   cout << s.p;
    else cout << endl;
    return cout;
}

// 加号运算符重载1：ss + s 拼接
MyString operator+(const char *ss, MyString s)
{
    char *buf = new char[strlen(ss) + strlen(s.p) + 1];
    strcpy(buf, ss);
    strcat(buf, s.p);
    MyString temp(buf);
    delete[] buf;
    return temp;
}

// 加号运算符重载2：s + ss 拼接
MyString operator+(MyString s, const char *ss)
{
    char *buf = new char[strlen(s.p) + strlen(ss) + 1];
    strcpy(buf, s.p);
    strcat(buf, ss);
    MyString temp(buf);
    delete[] buf;
    return temp;
}

int CompareString(const void *e1, const void *e2)
{
    MyString *s1 = (MyString *)e1;
    MyString *s2 = (MyString *)e2;
    if (*s1 < *s2)
        return -1;
    else if (*s1 == *s2)
        return 0;
    else if (*s1 > *s2)
        return 1;
}

int main()
{
	MyString s1("abcd-"),s2,s3("efgh-"),s4(s1);
	MyString SArray[4] = {"big","me","about","take"};
	cout << "1. " << s1 << s2 << s3<< s4<< endl;
	s4 = s3;
	s3 = s1 + s3;
	cout << "2. " << s1 << endl;
	cout << "3. " << s2 << endl;
	cout << "4. " << s3 << endl;
	cout << "5. " << s4 << endl;
	cout << "6. " << s1[2] << endl;
	s2 = s1;
	s1 = "ijkl-";
	s1[2] = 'A' ;
	cout << "7. " << s2 << endl;
	cout << "8. " << s1 << endl;
	s1 += "mnop";
	cout << "9. " << s1 << endl;
	s4 = "qrst-" + s2;
	cout << "10. " << s4 << endl;
	s1 = s2 + s4 + " uvw " + "xyz";
	cout << "11. " << s1 << endl;
	qsort(SArray,4,sizeof(MyString),CompareString);
	for( int i = 0;i < 4;i ++ )
	cout << SArray[i] << endl;
	//s1的从下标0开始长度为4的子串
	cout << s1(0,4) << endl;
	//s1的从下标5开始长度为10的子串
	cout << s1(5,10) << endl;
	return 0;
}