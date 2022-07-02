#include <iostream>
using namespace std;

// OOP Overview and Features


class Box {
public:
	Box(double h, double w, double l) : height(h), width(w), length(l) {}
	double volume() { return height * width * length; }
	void print() {
		cout << height << " " << width << " " << length << endl;
	}
private:
	double height, width, length;
};

void main() {
	Box b(10, 20, 30);
	b.print();
	cout << b.volume() << endl;
}