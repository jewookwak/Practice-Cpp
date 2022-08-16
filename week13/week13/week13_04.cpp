#include<iostream>
#include<vector>
#include<string>
#include<list>
using namespace std;

template <class IteratorT>
void display(IteratorT start, IteratorT end)
{
	for (IteratorT p = start; p != end; ++p) {
		cout << *p << " ";
	}
}

int main()
{
	list<int> li;
	vector<string>vs;
	for (int i = 1; i < 12; ++i) {
		li.push_back(i);
	}
	vs.push_back("Now"); vs.push_back("Is"); vs.push_back("The");
	vs.push_back("Time"); vs.push_back("For"); vs.push_back("All");
	cout << "li: "; display(li.begin(), li.end()); cout << endl;
	cout << "vs: "; display(vs.begin(), vs.end()); cout << endl;
	/*
	for (vector<string>::iterator IterPos = vs.begin();IterPos != vs.end(); ++IterPos)
	{
		cout << *IterPos << " ";
	}
	*/
	
	return 0;

}