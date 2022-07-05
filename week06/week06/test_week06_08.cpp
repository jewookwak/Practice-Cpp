#include <iostream>
using namespace std;

class Box {
public:
	Box() {
		height = width = length = 0;
		cout << "Constructor 0" << endl;
	}
	Box(double h, double w, double l) : height(h), width(w), length(l) {
		cout << "Constructor 1" << endl;
	}
	~Box() {
		cout << "Destructor" << endl;
	}
	double height, width, length;
};

void main() {
	Box box1;
	Box box2(1, 1, 1);
}