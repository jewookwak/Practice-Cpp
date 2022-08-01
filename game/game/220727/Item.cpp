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
	std::cout << "�̸� : " << m_Name << "\t���� : ";
	switch (m_Type)
	{
	case EItemType::Weapon:
		std::cout << "����" << std::endl;
		std::cout << "���ݷ� : " << m_Option << std::endl;
		break;
	case EItemType::Armor:
		std::cout << "��" << std::endl;
		std::cout << "���� : " << m_Option << std::endl;
		break;
	}

	std::cout << "Price : " << m_Price << "\tSell : " << m_Sell << std::endl;
}

CItem* CItem::Clone()
{
	return new CItem(*this);
}
