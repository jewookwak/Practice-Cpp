#include <iostream>
using namespace std;
//Flow of Destructor
//Destructor exexuted when main is over. Dectructor's order is reverse order of Constructor.
/*
When object of derived class is destroyed, destructor of the derived class is executed, then, destructor of the base class is executed.
Order of destruction made in stack is the reverse of the order of creation.
*/
class Base
{
private:
	int baseNum;

public:
	Base(int n) : baseNum(n)
	{
		cout << "Base(): " << baseNum << endl;
	}
	~Base()
	{
		cout << "~Base():" << baseNum << endl;
	}

};

class Derived : public Base
{
private:
	int derivNum;
public:
	Derived(int n) :Base(n), derivNum(n)
	{
		cout << "Derived() : " << derivNum << endl;
	}
	~Derived()
	{
		cout << "~Derived():" << derivNum << endl;
	}
};

int main()
{
	Derived drv1(15);
	Derived drv2(27);
	return 0;
}