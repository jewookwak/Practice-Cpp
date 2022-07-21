#include <iostream>
using namespace std;
// Defining own Assignment Operator.
class Array {
public :
	Array(size_t num) : size(num) {
		cout << "Constructor 0" << endl;
		ptr = new int[num];
	}
	Array(const Array& arr) : size(arr.size) {
		cout << "Copy Constructor" << endl;
		ptr = new int[size];
		for (size_t i = 0; i < size; i++)
			ptr[i] = arr.ptr[i];
	}
	~Array() {
		cout << "Destructor Start" << endl;
		if (ptr != NULL) delete[] ptr;
		cout << "Destructor End" << endl;
	}
	Array& operator=(const Array& arr) {
		cout << "Assignment" << endl;
		if (ptr != NULL) delete[] ptr;
		size = arr.size;
		ptr = new int[arr.size];
		for (size_t i = 0; i < size; ++i)
			ptr[i] = arr.ptr[i];
		return (*this);
	}
	int* ptr;
	size_t size;
};
void f() {
	Array array(5);
	Array array0(10), array1(10);
	array1 = array0 = array;
}
void main() { f(); }