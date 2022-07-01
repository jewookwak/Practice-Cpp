#include <iostream>
using namespace std;

int main()
{
	int ia[] = { 6,5,4,3,2,1 };
	int* ptr_i = &ia[3];

	double da[] = { 6.1,5.1,4.1,3.1,2.1,1.1,0.1 };
	double* ptr_d = &da[3];

	cout << ptr_i[2] << endl;
	cout << ptr_i[0] << endl;
	cout << ptr_i[-1] << endl;
 	std::cout << *(ptr_i + 2) << std::endl;
	std::cout << *(ptr_d + 2) << std::endl;
}