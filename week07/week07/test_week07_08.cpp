#include <iostream>
using namespace std;

// When is copy constructor called -> When a function is called(call-by-value)

class Box {
public:
	Box(double w, double h, double l) : width(w), height(h), length(l) {}

	Box(const Box& b) :width(b.width), height(b.height), length(b.length) {
		cout << "Copy Constructor" << endl;
	}
private:
	double width, height, length;
};

void func(Box box) { //copy constructor is called

}
void main() {
	Box box1(1, 2, 3);
	func(box1);	
}