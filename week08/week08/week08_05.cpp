#include<iostream>
using namespace std;
// Access to Protected Members
/*
Protected
-Accessible within the class definition or within the definition of child classes.
-Protected means that we have less encapsulation.
-Use protected only where it is really necessary.
*/

class Base
{
private:
	int num1;
protected:
	int num2;
public:
	int num3;
	Base()
	{
		num1 = 1; num2 = 2; num3 = 3;
	}
	void ShowData()
	{
		cout << num1 << ", " << num2 << ", " << num3 << endl;
	}
};

class Derived : public Base
{
public:
	void ShowBaseMember()
	{
		//cout << num1;  ===> Compile Error
		cout << num2 << endl; // OK
		cout << num3 << endl; // OK
	}
};

int main()
{
	Derived drv1;
	drv1.ShowBaseMember();
	return 0;
}