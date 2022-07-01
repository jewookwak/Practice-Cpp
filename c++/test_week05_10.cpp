#include <iostream>
using namespace std;



void initialize(int list[], int size, int value);
void print(int list[], int size);
int* addElement(int list[], int& size, int value);
int* deleteFirst(int list[], int& size);

int main() {
	/* The way to declare Dynamic (List)
	int* p, n = 10;
	p = new int;
	p = new int[100];
	p = new int[10];
	*/

	// A simple Dynamic List Example!!
	cout << "Enter list size : ";
	int n;
	cin >> n;
	int* A = new int[n];
	if (n <= 0) {
		cout << "bad size" << endl;
		return 0;
	}
	initialize(A, n ,0); // initialize the array A with value 0
	print(A, n);
	A = addElement(A, n, 5);
	print(A, n);
	A = deleteFirst(A, n);
	print(A, n);
	delete[] A;
	return 0;
}

void initialize(int list[], int size, int value) {
	for (int i = 0; i < size; i++)
		list[i] = value;
}

void print(int list[], int size) {
	cout << "[";
	for (int i = 0; i < size; i++)
		cout << list[i] << " ";
	cout << "]" << endl;
}

// for adding a new element to end of array
int* addElement(int list[], int& size, int value) {
	int* newList = new int[size + 1]; // make new array
	if (newList == 0) {
		cout << "Memory allocation error for addElement!" << endl;
		exit(-1);
	}
	for (int i = 0; i < size; i++) {
		newList[i] = list[i];
		if (size)
			delete[] list;
		newList[size] = value;
		size++;
		return newList;
	}
}

int* deleteFirst(int list[], int& size) {
	if (size <= 1) {
		if (size) {
			delete list;
			size = 0;
		}
		return NULL;
	}
	int* newList = new int[size - 1]; // make new array
	if (newList == 0) {
		cout << "Memory allocation error for delete First!" << endl;
		exit(-1);
	}
	for (int i = 0; i < size - 1; i++)
		newList[i] = list[i + 1];
	delete[] list;
	size--;
	return newList;
}