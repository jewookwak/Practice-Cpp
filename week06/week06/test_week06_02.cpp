#include <iostream>
using namespace std;
// Template (polymorphism) Templates allow a function or class to work on many different data types without being rewritten for each one.

template<typename T>
T minimum(T a, T b) { return (a < b) ? a : b; }

void main() {
	int i0 = 3, i1 = 5;
	float f0 = -5.1f, f1 = 1.0f;
	cout << minimum(i0, i1) << endl;
	cout << minimum(f0, f1) << endl;
}