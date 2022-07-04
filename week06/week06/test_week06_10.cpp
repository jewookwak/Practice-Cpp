#include <iostream>
using namespace std;
/*
Memory Leak in a User Defined Class
*/
class Array {
public:
	Array() : ptr(NULL) {
		cout << "Constructor 0 " << endl;
	}
	Array(size_t num) { // here I used size_t instead of int because size of int is defferent in each system.
		ptr = new int[num];
		cout << "Constructor 1" << endl;
	}
	~Array() {
		if (ptr != NULL) delete[] ptr;
		cout << "Destructor" << endl;
	}

	int* ptr;
	int a, * b;

};

void f() {
	Array var(10);
}
void main() {
	f();  // Without ~Array() there will be memory leak in f()
		  // Memory pointed by ptr is not deleted.
}