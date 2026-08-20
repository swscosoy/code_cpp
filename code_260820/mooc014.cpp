#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class MyString {
	char * p;

public:
	MyString(const char * s) {
		if( s) {
			p = new char[strlen(s) + 1];
			strcpy(p,s);
		}
		else
			p = NULL;

	}
	~MyString() { if(p) delete [] p; }
// 在此处补充你的代码
    friend ostream& operator<<(ostream& cout, MyString& s);

    MyString& operator=(const char * s){
        if(s) {
            delete [] p;
            p = new char[strlen(s) + 1];
			strcpy(p,s);
		}
		else
			this->p = NULL;
        return *this;
    }

    MyString(const MyString &s){
        if(s.p) {
            p = new char[strlen(s.p) + 1];
			strcpy(this->p,s.p);
		}
		else
			this->p = NULL;
    }

    MyString &operator=(MyString &s){
        if(s.p) {
            delete [] p;
            p = new char[strlen(s.p) + 1];
			strcpy(this->p,s.p);
		}
		else
			this->p = NULL;
        return *this;
    }

    void Copy(const char * s){
        if(s) {
			this->p = new char[strlen(s) + 1];
			strcpy(this->p,s);
		}
		else
			this->p = NULL;
    }
    
};

ostream &operator<<(ostream& cout, MyString &s){
    cout << s.p;    
    return cout;
};

int main()
{
	char w1[200],w2[100];
	while( cin >> w1 >> w2) {
		MyString s1(w1),s2 = s1;
		MyString s3(NULL);
		s3.Copy(w1);
		cout << s1 << "," << s2 << "," << s3 << endl;
		s2 = w2;
		s3 = s2;
		s1 = s3;
		cout << s1 << "," << s2 << "," << s3 << endl;		
	}
}