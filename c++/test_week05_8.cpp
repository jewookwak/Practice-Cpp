#include <iostream>
using namespace std;

int main()
{
	int twod[3][4] = { {0,1,2,3},{4,5,6,7},{8,9,10,11} };
	int oned[12];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++){
			oned[i * 4 + j] = twod[i][j];
			
		}
	}
	for (int i = 0; i < 12; i++) {
		cout << oned[i] << endl;
	}
	return 0;
}