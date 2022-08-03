#include <iostream>
using namespace std;
// An Example of Virtual Function
class Animal {
public:
	virtual void eat()
	{
		cout << "I eat like a generic Animal. \n";
	}
};

class Wolf : public Animal {
public: 
	void eat() { cout << "I eat like a wolf! \n"; }
};

class Fish : public Animal {
public:
	void eat() {
		cout << "I eat like a fish! \n";
	}
};

class OtherAnimal : public Animal {};

int main()
{
	Animal* anAnimal[4];
	//dynamic binding
	anAnimal[0] = new Animal();
	anAnimal[1] = new Wolf();
	anAnimal[2] = new Fish();
	anAnimal[3] = new OtherAnimal();
	for (int i = 0; i < 4; i++)
		anAnimal[i]->eat();
	return 0;
}