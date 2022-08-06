#include <iostream>
using namespace std;
// An Example of Template
/*
- The typename keyword may be replaced by class
- We can specify more than two template type
*/
template <class T1, class T2>
//template<typename T1, typename T2>
void ShowData(double num)
{
	cout << (T1)num << ", " << (T2)num << endl;
}

int main()
{
	ShowData<char, int>(65);
	ShowData<char, int>(67);
	ShowData<char, double>(68.9);
	ShowData<short, double>(69.2);
	ShowData<short, double>(70.4);
	return 0;
}