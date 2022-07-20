#include <iostream> 
using namespace std;

//When I need to define my own copy constructor?
//Synthesized copy constructor can be problematic when dynamic allocation!

class Array {
public:
	Array(size_t num) : size(num) {
		cout << "Constructor 0 " << endl;
		ptr = new int[num];
	}
	~Array() {
		cout << "Destructor Start" << endl;
		if (ptr != NULL) delete[] ptr;
		cout << "Destructor End" << endl;
	}
	int* ptr;
	size_t size;
};
void f() {				// If delete array then there is no pointer that array0 can point.
	Array array(5);
	Array array0(array);
}
void main() {
	f();
} 