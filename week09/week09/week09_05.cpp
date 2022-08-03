#include <iostream>
using namespace std;
// An example of function overriding


class First
{
public:
	void FirstFunc() { cout << "FirstFunc" << endl; }

};
class Second : public First
{
public:
	void SecondFunc() { cout << "SecondFunc" << endl; }

};
class Third : public Second
{
public:
	void ThirdFunc() { cout << "ThirdFunc" << endl; }
};

int main()
{
	Third* tptr = new Third();
	Second* sptr = tptr;
	First* fptr = sptr;

	tptr->FirstFunc();
	tptr->SecondFunc();
	tptr->ThirdFunc(); // Third inherited First, Second so Ok to compile SecondFunc(), ThirdFunc()
	/*
	sptr->FirstFunc();
	sptr->SecondFunc();
	sptr->ThirdFunc(); // Error!  // Compiler doesn't know sptr points to Third(). Compiler only consider pointer type when it is declared (Second *sptr = ~~)

	fptr->FirstFunc();
	fptr->SecondFunc(); // Error!
	fptr->ThirdFunc(); // Error!
	
	// -> is a way to approach class member using pointer.
	*/
	delete tptr;
	return 0;
}