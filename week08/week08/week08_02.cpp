#include <iostream>

using namespace std;
// Has-A Relationship
class Gun
{
private:
	int bullet;
public:
	Gun(int bnum) :bullet(bnum)
	{}
	void Shot()
	{
		cout << "Shot" << endl;
		bullet--;
	}
	void Print1()
	{
		cout << "Bullet num : " << bullet << endl;
	}
};
class Police : public Gun
{
private:
	int handcuffs;
	
public:
	Police(int bnum, int bcuff) :Gun(bnum), handcuffs(bcuff)
	{}
	void PutHandCuff()
	{
		cout << "HandCuff" << endl;
		handcuffs--;
	}
	void Print2()
	{
		cout << "HandCuff num : " << handcuffs << endl;
	}
};


int main()
{
	Police pman(5, 3);
	pman.Shot();
	pman.PutHandCuff();
	pman.Print1();
	pman.Print2();
	return 0;
}