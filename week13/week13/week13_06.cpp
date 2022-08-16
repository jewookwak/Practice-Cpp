#include<iostream>
#include<algorithm>
#include<string>
#include<list>
using namespace std;
// Example of STL Algorithm (find)
int main()
{
	list<string> composer;
	composer.push_back("Mozart");
	composer.push_back("Bach");
	composer.push_back("Chopin");
	composer.push_back("Beethover");

	list<string>::iterator p;
	p = find(composer.begin(), composer.end(), "Bach");
	cout << "Found: " << *p << endl;
	if (p == composer.end())
	{
		cout << "Not found." << endl;
	}
	else if (++p != composer.end()) {
		cout << "Found before: " << *p << endl;
	}
	else {
		cout << "Found at the end." << endl;
	}

}