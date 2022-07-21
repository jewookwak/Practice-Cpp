#include <iostream>
using namespace std;

//Non-member Operator Overloading

class vec2 {
public:
	vec2() : x(0), y(0) {}
	vec2(float a, float b) : x(a), y(b) {}

	float x, y;
};
vec2 operator+(const vec2& a, const vec2& b)
{
	return vec2(a.x + b.x, a.y + b.y);
}

void main() {
	vec2 a(1.1f, 0), b(1.3f, 2.5f);
	vec2 x0 = a + b;
	cout << x0.x<<" " << x0.y << endl;
}