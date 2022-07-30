#include <iostream>
using namespace std;
// Protected and Private Inheritance
/*
Public inheritance
Inherit right of access control intactly. But, inherit "private" as inaccessible

Protected inheritance
Inherit members with a wider scope than protected as "protected". But inherit "private" as inacessible.
Can't access parent valiable in main()


Private inheritance
Inherit members with a wider scope than private as "private" But, inherit "private" as inaccessible.
Can't access variable in other inherit class
*/

class Base
{
private:
	int num1;
protected:
	int num2;
private:
	int num3;
};

class Derived : protected Base
{};

int main()
{
	Derived drv;
	//cout << drv.num3 << endl; ===>  Compile Error     ---> Base is called by protected
	return 0;
}