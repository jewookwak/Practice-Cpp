#pragma once

#include "GameInfo.h"

class CItem
{
public:
	CItem();
	CItem(const CItem& Item);
	~CItem();

private:
	char		m_Name[32];
	EItemType	m_Type;
	int			m_Option;	// ������ ��� ���ݷ�, ���� ��� ����.
	int			m_Price;
	int			m_Sell;

public:
	EItemType GetItemType()
	{
		return m_Type;
	}

	int GetOption()
	{
		return m_Option;
	}

	int GetPrice()
	{
		return m_Price;
	}

	int GetSell()
	{
		return m_Sell;
	}

public:
	bool Init(const char* Name, EItemType Type, int Option, int Price, int Sell);
	void Output();
	CItem* Clone();
};

