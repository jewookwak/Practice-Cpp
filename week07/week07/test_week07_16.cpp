#include <iostream>
using namespace std;
// Must make 3 things if you use dynamic allocation in class.
class Array {
public:
	Array(size_t num) : size(num) {				// 1. Copy constructor!!!
		cout << "Constructor 0" << endl;
		ptr = new int[num];
	}

	~Array() {									// 2. Destructor !!
		cout << "Destructor Start" << endl;
		if (ptr != NULL) delete[] ptr;
		cout << "Destructor End" << endl;
	}
	Array& operator=(const Array& arr) {		// 3. Assignment Operator !!
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
