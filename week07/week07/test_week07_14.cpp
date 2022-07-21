#include <iostream>
using namespace std;
// Another way of defining + on vec2
class vec2 {
public : 
	vec2() : x(0), y(0) {}
	vec2(float a, float b) : x(a), y(b) {}

	vec2 operator+(const vec2& a)
	{
		return vec2(x + a.x, y + a.y);
	}
	float x, y;
};
void main() {
	vec2 a(1.1f, 0), b(1.3f, 2.5f);
	vec2 x0 = a + b; 
	//vec2 x0 = a.operator +(b);
	cout << x0.x << " " << x0.y << endl;
}
