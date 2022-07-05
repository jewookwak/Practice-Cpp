#include <iostream>
using namespace std;

class Box {
public:
	void set(double h, double w =1, double l =1 ){
		height = h; width = w; length = l;
	}
	double volume() const { return height * width * length; }

	double height, width, length;

};

void main() {

	Box box;
	box.set(1);
	box.set(2, 3);
	cout << box.volume() << endl;

}
