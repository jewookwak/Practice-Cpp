#include <iostream>
using namespace std;
// Template
/*
- A template is a feature of the C++ programming laguage that allows functions and calsses to work with generic types
- It allows function or class to operate on many different data types without having to rewrite them individually
- How can we make the template?

- Function template
 - Template which is used for making a function
- The typename keyword may be replaced by class
*/

template <typename T>
T Add(T num1, T num2)
{
	return num1 + num2;
}

int main()
{
	cout << Add<int>(15, 20) << endl;
	cout << Add<double>(2.9, 3.7) << endl;
	cout << Add<int>(3.2, 3.2) << endl;
	cout << Add<double>(3.14, 2.75) << endl;

	return 0;
}