#include<iostream>
using namespace std;
// An Example of Abstract Class

class Animal
{
public:
	virtual ~Animal() {} // virtual destructor
	virtual void Cry() = 0; // Pure virtual function
};
class Dog : public Animal
{
public:
	virtual void Cry() { cout << "Dog Cry!" << endl; }
};

class Cat : public Animal
{
public:
	virtual void Cry() { cout << "Cat Cry!" << endl; }
};

int main(void)
{
	Dog my_dog;
	my_dog.Cry();
	Cat my_cat;
	my_cat.Cry();

	return 0;
}
