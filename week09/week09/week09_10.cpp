#include <iostream>
using namespace std;
// Virtual Destructor
/*
- Why we need virtual destructor?
	- Virtual destructors are useful when you can delete an instance of a derived class through a pointer to base class.
*/
class First
{
private:
	char* strone;
public:
	First(const char* str)
	{
		cout << "First()" << endl;
		strone = new char[strlen(str) + 1];
	}
	virtual ~First()  // virtual must be putted, virtual allow to execute object that pointer is really pointing at.
	{
		cout << "~First()" << endl;
		delete[]strone;
	}
};

class Second : public First
{
private:
	char* strtwo;
public: 
	Second(const char* str1, const char* str2) : First(str1)
	{
		cout << " Second()" << endl;
		strtwo = new char[strlen(str2) + 1];
	}
	~Second()
	{
		cout << "~Second()" << endl;
		delete[]strtwo;
	}
};

int main()
{
	First* ptr = new Second("simple", "complex");
	delete ptr;
	return 0;
}