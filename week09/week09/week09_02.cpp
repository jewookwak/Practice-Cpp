#include <iostream>
using namespace std;
//Operator Overloading
/*
Assign more than one meaning to Operator
Ex) + is adding two number, but you can assign other meaning defining operator+
*/

class Complex {
private:
	double val1, val2;
public:
	Complex(double val1, double val2) : val1(val1), val2(val2) {}
	Complex operator+(Complex& other);
	Complex operator-(Complex& other);
	Complex operator*(Complex& other);
	void Display() {
		cout << val1 << ", " << val2 << endl;
	}
};

// Operator overload using a member function
Complex Complex::operator+(Complex& other) /// a.operator+(b)  b is object here so object other is declared.
{      
	cout << other.val1 << ", " << other.val2 << endl; 
	return Complex(val1 + other.val1, val2 + other.val2);
}
Complex Complex::operator-(Complex& other) {
	cout << other.val1 << ", " << other.val2 << endl;
	return Complex(val1 - other.val1, val2 - other.val2);
}
Complex Complex::operator*(Complex& other) {
	cout << other.val1 << ", " << other.val2 << endl;
	return Complex(val1 * other.val1, val2 * other.val2);

}

int main()
{
	Complex a = Complex(1, 3);
	Complex b = Complex(5, 6);
	Complex c = Complex(0.0, 0.0);

	a.Display();
	b.Display();
	cout << endl;

	c = a + b;
	c.Display();
	c = a - b;
	c.Display();
	c = a * b;
	c.Display();
	return 0;
}