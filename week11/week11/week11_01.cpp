#include <iostream>
#include <list>
using namespace std;
// Standard Template Library / Squence container - List

class Item
{
public:
	int ItemID; int BuyMoney;
	Item(int itemID, int buyMoney)
	{
		ItemID = itemID;
		BuyMoney = buyMoney;
	}
};

int main()
{
	list<Item> Itemlist;

	//Insert item in the front
	Item item1(1, 1000);
	Itemlist.push_front(item1);
	
	Item item2(2, 2000);
	Itemlist.push_front(item2);

	//Insert item in the back
	Item item3(3, 3000);
	Itemlist.push_back(item3);

	Item item4(4, 4500);
	Itemlist.push_back(item4);
	
	//item code number (2,1,3,4)
	list<Item>::iterator iterEnd = Itemlist.end();
	for (list<Item>::iterator iterPos = Itemlist.begin(); iterPos != iterEnd; ++iterPos)
	{
		cout << "item code : " << iterPos->ItemID << endl;
	}
}