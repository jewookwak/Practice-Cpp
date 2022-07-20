#include <iostream>
using namespace std;

// When is copy constructor called -> When an object is created.

class Box {
public :
	Box(double w, double h, double l) : width(w), height(h), length(l) {}

	Box(const Box& b) :width(b.width), height(b.height), length(b.length) {
		cout << "Copy Constructor" << endl;
	}
private : 
	double width, height, length;
};

void main() {
	Box box(1, 2, 3);

	Box box_1(box);						//Copy constructor is called.
	Box box_3(0,0,0); box_3 = box;		//Copy constructor is not called.
										//Assignment operator is called instead.
	Box box_2 = box;					//Copy constructoris called.
}