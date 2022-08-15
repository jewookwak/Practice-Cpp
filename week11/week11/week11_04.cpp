#include<iostream>
#include<set>
using namespace std;
//Associative Container : An Example2 of STL set

int main()
{
	set<int> set1;
	set1.insert(10);
	set1.insert(15);
	set1.insert(12);
	set1.insert(2);
	set1.insert(100);
	cout << "All element: " << endl;
	for (set<int>::iterator IterPos = set1.begin(); IterPos != set1.end(); ++IterPos)
	{
		cout << *IterPos << " ";
	}

	set<int>::iterator IterPos = set1.begin();
	++IterPos;
	set1.insert(IterPos, 90);

	cout << endl;
	cout << "All element: " << endl;
	for (set<int>::iterator IterPos = set1.begin(); IterPos != set1.end(); ++IterPos)
	{
		cout << *IterPos<< " ";
	}
	cout << endl;
	return 0;

}