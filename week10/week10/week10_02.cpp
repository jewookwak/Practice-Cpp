#include <iostream>
using namespace std;
// Overloading based on global function
// Use friend in class and Overload the operator function on global place.

class point
{
private:
	int xpos, ypos;
public:
	point(int x=0, int y=0): xpos(x),ypos(y) 
	{}
	void ShowPosition() const
	{
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
	friend point operator+(const point& pos1, const point& pos2);
};
point operator+(const point& pos1, const point &pos2)
{
	point pos(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);
	return pos;
}
int main()
{
	point pos1(3, 4);
	point pos2(10, 20);
	//point pos3 = pos1.operator+(pos2);
	point pos3 = pos1 + pos2;
	pos1.ShowPosition();
	pos2.ShowPosition();
	pos3.ShowPosition();
}