#include <iostream>
using namespace std;

// Function Overriding
/*
- C++ Compiler determines whether a pointer operation is possible based on the type of the pointer type.
- It does not determines based on the type of actual pointed object.
*/

class Base
{
public:
	void BaseFunc()
	{
		cout << "Base Function" << endl;
	}
};

class Derived : public Base
{
public:
	void DerivedFunc()
	{
		cout << "Derived Function" << endl;
	}
};
/*

int main()
{
	Base* bptr = new Derived(); //Compile OK!
	bptr->DerivedFunc(); //Compile Error!
}

int main()
{
	Base* bptr = new Derived(); //Compile OK!
	Derived *dptr= bptr; //Compile Error!
}
*/
int main() {
	Derived* dptr = new Derived();
	Base* bptr = dptr;
}