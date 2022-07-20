#include <iostream>
using namespace std;

//friend : friend declaration allows a class to grant access to its nonpublic members to 
//specified functions or classes

class X {
public:
	X() {}
	friend class Y;
	friend int f(void);
private:
	int a, b, c;

};
class Y {
public :
	Y() {}
	void func(X& var) {				// Class X를 reference 로 받음.
		var.a = var.b = var.c = 1; // It is OK.
									//Class Y is a friend of class X

	}
};
int f(void) {

	X x;
	Y y;
	y.func(x);
	return x.a + x.b + x.c;			//It is ok. Function f is a friend func of x.
}
int main() {
	cout << f() << endl;
	return 0;
}