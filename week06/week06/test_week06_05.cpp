#include <iostream>

using namespace std;
/*
Inline Member Functions
*/


class Box {
public:
	Box() {}
	void set(double h, double w, double l) {
		height = h, width = w, length = l;
	}
	double area() const;
	inline double volume() const;
	double height, width, length;
};
	
	double Box::area() const {
		return 2 * (height * width * + width * length + length * height);
	}
	inline double Box::volume() const {
		return height * width * length;
	}
void main() {
	Box box;
	box.set(1, 2, 3);
	cout << box.volume() << endl;
}