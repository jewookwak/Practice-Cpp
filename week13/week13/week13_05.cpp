#include<iostream> 
#include<vector> 
#include<string>
#include<algorithm>
using namespace std;
// Example of STL Algorithm (sort)
template<class Iterator>
void Display(Iterator start, Iterator end)
{
	for (Iterator p = start; p != end; ++p)
		cout << *p << " ";
}

int main()
{
	vector<string> v1;
	v1.push_back("M"); v1.push_back("B");
	v1.push_back("C"); v1.push_back("D");
	cout << "before sort: "; Display(v1.begin(), v1.end()); cout << endl;
	sort(v1.begin(), v1.end());
	cout << "after sort: "; Display(v1.begin(), v1.end()); cout << endl;

	vector<int> v2;
	v2.push_back(12);
	v2.push_back(11);
	v2.push_back(10);
	cout << "before sort: "; Display(v2.begin(), v2.end()); cout << endl;
	sort(v2.begin(), v2.end());
	cout << "after sort: "; Display(v2.begin(), v2.end()); cout << endl;



	return 0;
}