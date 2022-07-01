#include <iostream>
using namespace std;

int main()
{
	int a = 1, b = 2, c = 3;
	int* p[5];
	p[0] = &a;
	p[1] = &b;
	p[2] = &c;

	int list[5] = { 9, 8, 7, 6, 5 };
	int* point;
	point = list; //points to 1st entry
	cout << "point = " << *point << endl;

	point = &list[0]; //points to 1st entry
	cout << "point = " << *point << endl;

	point = &list[1]; //points to 2st entry
	cout << "point = " << *point << endl;

	point = list + 1; //points to 2st entry
	cout << "point = " << *point << endl;
}