#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	char src[] = "1234567890";
	char dest[] = "abcdefghij";
	copy(&src[3], &src[7], &dest[5]);
	puts(dest);
}