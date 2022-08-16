#include <iostream>
using namespace std;
// Example of Find() with an Integer Iterator
template <typename IteratorT, typename T> 
IteratorT Find(IteratorT begin, IteratorT end, const T& value)
{
	for (; begin != end; begin++)
		if (*begin == value)
			break;
	return begin;
}

int main()
{
	const int SIZE = 100;
	int arr[SIZE];
	int num;

	int* begin = arr;
	int* end = &arr[SIZE];

	for (int i = 0; i < SIZE; ++i)
	{
		arr[i] = 2 * i;
	}

	while (true) {
		cout << "Enter number : "; cin >> num;
		int* position = Find(begin, end, num);
		if (position != end) {
			++position;
			if (position != end)
				cout << "Found before " << *position << endl;
			else
				cout << "Found as last element" << endl;
		}
		else
			cout << "Not found" << endl;
	}
}