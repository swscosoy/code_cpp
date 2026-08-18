#include <iostream>
using namespace std;

int main()
{
	int * a[] = { NULL, new int(2), new int(3), new int[10] };
	
	*a[2] = 123;
	a[3][5] = 456;
	if(! a[0] ) {
		cout << * a[2] << "," << a[3][5];
	}
	delete a[0];
	delete a[1];
	delete a[2];
	delete[] a[3];
	return 0;
}