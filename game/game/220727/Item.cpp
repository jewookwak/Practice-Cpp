#include "Item.h"

CItem::CItem()	:
	m_Name{},
	m_Option(0),
	m_Price(0),
	m_Sell(0)
{
}

CItem::CItem(const CItem& Item)
{
	*this = Item;
}

CItem::~CItem()
{
}

bool CItem::Init(const char* Name, EItemType Type, int Option, int Price, int Sell)
{
	strcpy_s(m_Name, Name);
	m_Type = Type;
	m_Option = Option;
	m_Price = Price;
	m_Sell = Sell;

	return true;
}

void CItem::Output()
{
	std::cout << "이름 : " << m_Name << "\t종류 : ";
	switch (m_Type)
	{
	case EItemType::Weapon:
		std::cout << "무기" << std::endl;
		std::cout << "공격력 : " << m_Option << std::endl;
		break;
	case EItemType::Armor:
		std::cout << "방어구" << std::endl;
		std::cout << "방어력 : " << m_Option << std::endl;
		break;
	}

	std::cout << "Price : " << m_Price << "\tSell : " << m_Sell << std::endl;
}

CItem* CItem::Clone()
{
	return new CItem(*this);
}
