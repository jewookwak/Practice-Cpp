#include <iostream>
using namespace std;
// Enforcing Encapsulation!!!
class Box {
public:
	Box() : height(0), width(0), length(0), area(0), volume(0) {}

	void set(double h, double w, double l) {
		height = h; width = w; length = l;
		area = 2 * (h * w + w * l + l * h);
		volume = h * w * l;
	}
	void print() const {
		cout << "Box : (" << height << ", " << width << ", " << length << ")" << endl;
		cout << "Area : " << area << endl;
		cout << "volume : " << volume << endl;
	}
private: // private variable <- cannot access directly in main() function
	double height, width, length;  
	double area, volume;
};

void main() {
	Box box1;
	box1.set(1, 2, 3);
	box1.print();
	box1.set(30, 30, 30); // If I type like ( box1.height= box1.width= box1.length =30; ). It produce an error!!
	box1.print();
}