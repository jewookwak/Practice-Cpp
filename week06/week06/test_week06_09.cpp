#include <iostream>
#include <string>
/* Memory Leak */
using namespace std;

void print() {
	string* str = new string("Programming Methodology is easy");
	cout << *str << endl;
	delete str; // explicit delete to void memory leak.
}
void main()
{
	while (1) print();
}