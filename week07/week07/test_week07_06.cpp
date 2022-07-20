#include <iostream>
using namespace std;

// copy constructor

class Box {
public :
	Box(double w, double h, double l) : width(w), height(h), length(l) {}
	Box(const Box& b): width(b.width), height(b.height), length(b.length) {}

	void print()
	{
		cout << "width : " << width << " height : " << height << " length : " << length << endl;
	}
private : 
	double width, height, length;

	
};

void main() {
	Box box(1,2,3);

	Box box_1(box); //copy constructor is called
	box.print();
	box_1.print();
}
