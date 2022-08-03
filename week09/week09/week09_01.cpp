#include <iostream>
using namespace std;
// Polymorphism
/*
Four Different Forms of Polymorphism
- Overloading (not related to inheritance)
- Overrding (under inheritance)
- Polymorphic variable (assignment polymorphism)
- Generics(templates)
*/
// Function Overloading & Default Parameter

void Func(int one, int two = 2, int three = 3);
void Func(float fv);
void Func(int one, int two, int three)
{
	cout << "int One = " << one << endl;
	cout << "int Two = " << two << endl;
	cout << "int Three = " << three << endl << endl;
}
void Func(float fv)
{
	cout << "flot One = " << fv << endl;
}

void main()
{
	Func(10, 20, 30);
	Func(10, 20);
	Func(10);
	Func(1.5f);

}