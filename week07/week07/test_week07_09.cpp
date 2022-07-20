#include <iostream>
using namespace std;

// Synthesized Copy Constructor
// If we do not define the copy constructor, the compiler automatically creates one for us.
// You need to note that the synthesized copy constructor makes member-wise copy only at the top-level

class Array {
public :
	Array(size_t num) : size(num) { ptr = new int[num]; }
	~Array() { if (ptr != NULL) delete[] ptr; }

	//Array(const Array& array) : ptr(array.ptr), size(array.size) {} // -> Synthesized copy constructor created automatically by the compiler

	int* ptr;
	size_t size;
};

void main()
{

}