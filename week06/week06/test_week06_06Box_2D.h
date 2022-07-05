#include <iostream>
using namespace std;
namespace two_dim {
	class Box {
	public:
		void print() {
			cout << "### Box ###" << endl;
			cout << height << "\n" << width << "\n" << endl;
		}
		double height, width;
	};
}
