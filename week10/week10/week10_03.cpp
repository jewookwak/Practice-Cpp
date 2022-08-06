#include <iostream>
using namespace std;
// Unary Operator Overloading

class point
{
private:
	int xpos, ypos;
public:
	point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
	void ShowPosition() const
	{
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
	point& operator++()
	{
		xpos = xpos + 1;
		ypos = ypos + 1;
		return *this;
	}
	point& operator++(int)// This operator++ works on backside by adding int inside of ()
	{
		xpos = xpos + 1;
		ypos = ypos + 1;
		return *this;
	}
	friend point& operator--(point& ref);
	friend point& operator--(point& ref,int); // This operator-- works on backside by adding int inside of ()
};
point& operator--(point& ref)
{
	ref.xpos -= 1;
	ref.ypos -= 1;
	return ref;
}
point& operator--(point& ref,int)
{
	ref.xpos -= 1;
	ref.ypos -= 1;
	return ref;
}

int main()
{
	point pos(1, 2);
	++pos;
	pos.ShowPosition();
	--pos;
	pos.ShowPosition();
	++(++pos);
	pos.ShowPosition();
	--(--pos);
	pos.ShowPosition();
	pos++;
	pos.ShowPosition();
	pos--;
	pos.ShowPosition();
	return 0;
}