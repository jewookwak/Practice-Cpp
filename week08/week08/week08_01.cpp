#include <iostream>
#include <string.h>
using namespace std;
//inheritance
//Example of IS-A Relationship
class Person
{
private:
	int age;
	char name[50];
public:
	Person(int myage, const char* myname) : age(myage)
	{
		strcpy_s(name, myname);
	}
	void WhatYourName() const
	{
		cout << "My Name is " << name << endl;
	}
	void HowOldAreYou() const
	{
		cout << "I am " << age << " years old" << endl;
	}
};
class UnivStudent : public Person
{
private:
	char major[50];
public:
	UnivStudent(const char* myname, int myage, const char* mymajor) : Person(myage, myname)
	{
		strcpy_s(major, mymajor);
	}
	void WhoAreYou() const
	{
		WhatYourName();
		HowOldAreYou();
		cout << "my Major is " << major << endl << endl;
	}
};
int main()
{
	UnivStudent ustd1("Lee", 22, "Computer eng.");
	ustd1.WhoAreYou();
	UnivStudent ustd2("Yoon", 21, "Electronic eng");
	ustd2.WhoAreYou();
	return 0;
}
