#include <iostream>
using namespace std;
// Runtime Polymorphism
/*
- Property of OOP language
	- A variable declared as the parent type is allowed to hold a value derived from a child type.
	- Functions that use pointers or references to base classes msut be able to use objects of derived classes
- Dynamic binding + Virtual function
*/
class Shape {
protected:
	int width, height;
public:
	Shape(int a = 0, int b = 0) {
		width = a;
		height = b;
	}
	virtual int area() {   // virtual must be putted.
		cout << "Parent class area : " << endl;
		return 0;
	}
};
class Rectangle : public Shape {
public:
	Rectangle(int a = 0, int b = 0) : Shape(a, b) {}
	int area() {
		cout << "Rectangle class area : " << endl;
		return (width * height);
	}
};
class Triangle : public Shape {
public:
	Triangle(int a = 0, int b = 0) : Shape(a, b) {}
	int area() {
		cout << "Triangle class area : " << endl;
		return(width * height / 2);
	}
};

int main()
{
	Shape* shape;
	Rectangle rec(10, 7);
	Triangle tri(10, 5);

	shape = &rec;

	shape->area();

	shape = &tri;

	shape->area();
	return 0;
}