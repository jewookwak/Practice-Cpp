#include <iostream>
using namespace std;
// An Example of Template
// specialization of function template

template <typename T>
T Max(T a, T b) // compare magnitude of value. In case of charactor, It compare address magnitude.
{
	cout << "simple max" << endl;
	return a > b ? a : b;
}

template <>
char* Max(char* a, char* b) // compare length
{
	cout << "char* Max<char*>(char* a, char* b)" << endl;
	return strlen(a) > strlen(b) ? a : b;
}
template <>
const char* Max(const char* a, const char* b) // compare which on is latter word in dictionary
{
	cout << "const char* Max<const char*>(const char* a, const char* b)" << endl;
		return strcmp(a, b) > 0 ? a : b;
}
int main()
{
	cout << Max(11, 15) << endl;
	cout << Max('T', 'Q') << endl;
	cout << Max(3.5, 7.5) << endl;
	cout << Max("constant", "test1") << endl;

	char str1[] = "character";
	char str2[] = "test2";
	cout << Max(str1, str2) << endl;
	return 0;
}