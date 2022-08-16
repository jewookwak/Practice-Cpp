#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
// Example of STL Algorithm (find_if)
// Returns an iterator to the first element in the range for which applying function.
bool IsOdd(int i) {
	return ((i % 2) == 1);
}

int main() {
	vector<int> myvector;
	vector<int>::iterator it;

	myvector.push_back(10);
	myvector.push_back(25);
	myvector.push_back(40);
	myvector.push_back(50);

	it = find_if(myvector.begin(), myvector.end(), IsOdd);
	cout << "The fisrt odd value is " << *it << endl;

	return 0;
}