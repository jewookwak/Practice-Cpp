#include <iostream>
using namespace std;
//Flow of Constructors
//Construct of base class is called during creat process of derived class
//If there is no specified call for the constructor of base class in derived class, void constructor of the base class is called
class Base {
private:
	int baseNum;
public:
	Base() :baseNum(20)
	{
		cout << "Base()" << endl;
	}
	Base(int n) : baseNum(n)
	{
		cout << "SoBase(int n)" << endl;
	}
	void ShowBaseData()
	{
		cout << baseNum << endl;
	}
};

class Derived : public Base
{
private:
	int derivNum;
public:
	Derived() : derivNum(30)
	{
		cout << "Derived()" << endl;
	}
	Derived(int n) :derivNum(n)
	{
		cout << "Derived(int n)" << endl;
	}
	Derived(int n1, int n2) : Base(n1), derivNum(n2)
	{
		cout << "Derived(int n1, int n2)" << endl;
	}
	void showDerivData()
	{
		ShowBaseData();
		cout << derivNum << endl;
	}
};


int main()
{
	cout << "case1...." << endl;
	Derived dr1;
	dr1.showDerivData();
	cout << "____________________" << endl;
	cout << "case2....." << endl;
	Derived dr2(12);
	dr2.showDerivData();
	cout << " ___________________" << endl;
	cout << "case3....." << endl;
	Derived dr3(23, 24);
	dr3.showDerivData();
	return 0;
}