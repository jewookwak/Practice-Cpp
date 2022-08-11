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
	////////////////////////////////////////////////////////////////////////////////////

	// delete the item in the front
	Itemlist.pop_front();

	// return item in the front and print item code 1
	Item front_item = Itemlist.front();
	cout << "item ID: " << front_item.ItemID << endl;

	// delete the item in the back
	Itemlist.pop_back();

	//return the item in the back
	Item back_item = Itemlist.back();
	//print item code3
	cout << "item code : " << back_item.ItemID << endl;

	//Is there items?
	if (false == Itemlist.empty())
	{
		list<Item>::size_type count = Itemlist.size();
		cout << "the number of items: " << count << endl;
	}
	//Delete all items
	Itemlist.clear();
	list<Item>::size_type count = Itemlist.size();
	cout << "the number of items: " << count << endl;

}