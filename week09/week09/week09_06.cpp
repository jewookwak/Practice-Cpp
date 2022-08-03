#include <iostream>
using namespace std;
// Polymorphic Variable
/*
- Object pointer
- In C++, "A" type pointer variable can point "A" object or the objects which inherits "A"
*/
class Person
{
public:
	void Sleep() { cout << "Sleep" << endl; }
};
class Student : public Person
{
public:
	void Study() { cout << "Study" << endl; }
};
class PartTimeStudent : public Student
{
public:
	void Work() { cout << "Work" << endl; }
};
int main()
{
	Person* ptr1 = new Student();
	Person* ptr2 = new PartTimeStudent();
	Student* ptr3 = new PartTimeStudent();
	Student* ptr4 = new Student();
	PartTimeStudent* ptr5 = new PartTimeStudent();
	


	ptr1->Sleep();
	ptr2->Sleep();
	ptr3->Study();
	ptr4->Study();
	ptr4->Sleep();
	ptr5->Sleep();
	return 0;
}