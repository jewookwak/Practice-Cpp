#include <iostream>
using namespace std;

/*
Memory Allocation
*/
int main() {
	int** table;

	table = new int* [6];

	table[0] = new int[3];
	table[1] = new int[1];
	table[2] = new int[5];
	table[3] = new int[10];
	table[4] = new int[2];
	table[5] = new int[6];

	table[0][0] = 1; table[0][1] = 2; table[0][2] = 3;
	table[1][0] = 4;
	table[2][0] = 5; table[2][1] = 6; table[2][2] = 7; table[2][3] = 8; table[2][4] = 9;

	table[4][0] = 10; table[4][1] = 11;

	cout << _msize(table[0]) / sizeof(int) << endl;
	cout << _msize(table[1]) / sizeof(int) << endl;

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < (_msize(table[i]) / sizeof(int)); j++) {
			cout << table[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < 6; i++)
		delete[] table[i];
	delete[] table;

}