#include <iostream>
using namespace std;

void main()
{
	int a[5] = { 2, 4, 6, 8, 22 };
	int *p = a;
	cout << a[0] << " " << *p << " " << p << endl;
}