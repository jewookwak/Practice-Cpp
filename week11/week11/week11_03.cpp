#include <iostream>
#include <set>
using namespace std;
// Associative Container : An Example of STL set
int main()
{
	set<int> s;
	s.insert(40); s.insert(30); s.insert(50);
	s.insert(80); s.insert(10); s.insert(90);
	s.insert(70); s.insert(70);

	set<int>::iterator iter;
	for (iter = s.begin(); iter != s.end(); ++iter)
		cout << *iter << " ";
	cout << endl;

	cout << "count (50): " << s.count(50) << endl;
	cout << "count (100): " << s.count(100) << endl;
	cout << "count (70): " << s.count(70) << endl;

	iter = s.find(30);
	if (iter != s.end())
		cout << *iter << endl;
	s.clear();
	for (iter = s.begin(); iter != s.end(); ++iter)
		cout << *iter << " ";
	cout << endl;
	return 0;
}