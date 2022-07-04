#include <iostream>
using namespace std; 
namespace three_dim {


class Box {
public:
	void print() {
		cout << "Box : ";
		cout << height << " " << width << " " << length << endl;
	}
	double height, width, length;
};
}
