#include <iostream>
#include <vector>

using namespace std;

void main() {
	vector<int> ivec;
	for (int i = 5; i <= 10; ++i)
		ivec.push_back(i);

	// index approach
	for (vector<int>::size_type i = 0; i != ivec.size(); ++i)
		cout << ivec[i] << " ";
	cout << endl;


	// iterator approach
	for (vector<int>::iterator it = ivec.begin(); it != ivec.end(); ++it) {
		cout<< *it << " ";
	}
		
	cout << endl;

	
}