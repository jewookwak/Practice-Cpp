#include <iostream>
using namespace std;

void Pointer(int** pp, int* p, int x)
{
	cout << " pp = " << pp << endl;
	cout << " p = " << p << endl;
	cout << " x = " << x << endl;
}

void main()
{

	int a = 10;
	int *pointer = &a;
	int **ppointer = &pointer;
	cout << " ppointer : " << ppointer << endl;
	cout << " pointer : " << pointer << endl;
	cout << " a =  " << a << endl;
	Pointer(ppointer, pointer, a);
}