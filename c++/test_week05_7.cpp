#include <iostream>
using namespace std;

int main()
{
	int* p;
	p = 0;
	cout << p << endl; //print 0
	cout << &p << endl; //prints address of p
	// cout << *p << endl; //Error!
}