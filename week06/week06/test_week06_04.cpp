#include <iostream>
using namespace std;

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

	Box box(10,20,30);
	box.print();

}





class BB {
public:
	BB(double h, double w, double l) : height(h), width(w), length(l) {}
	double volume() {
		return height * width * length;
	}
	void print() {
		cout << height << " " << width << " " << length << endl;
	}
private:
	double height, width, length;
};
