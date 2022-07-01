#include <iostream>
using namespace std;
/*
Pointer to 2 - Dimensional Arrays
It's different way to code 2D array, compare it week05_8 file.
*/
int main() {
	int table[3][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			cout << *(*(table + i) + j)<< " ";
		}
		cout << endl;
	}
}