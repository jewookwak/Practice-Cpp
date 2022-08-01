#pragma once

#include "GameInfo.h"

class CInventory
{
private:
	CInventory();
	~CInventory();

private:
	static CInventory* m_Inst;

public:
	// cpp에 구현부분을 만들어주고자 하는 함수를 블록처리해서 Ctrl + . 을 누른 후에 c(선언/정의)를
	// 누르면 cpp에 자동으로 함수의 구현부분을 만들어준다.
	static CInventory* GetInst();
	static void DestroyInst();

private:
	// 이중포인터로 선언한 이유는 포인터 동적배열을 만들어주기 위해서이다.
	class CItem** m_Item;
	int		m_Count;	// 현재 인벤토리에 추가된 개수.
	int		m_MaxCount;	// 인벤토리에 아이템을 추가할 수 있는 최대 개수

public:
	int GetCount()
	{
		return m_Count;
	}

	int GetMaxCount()
	{
		return m_MaxCount;
	}

	bool IsFull()
	{
		return m_Count == m_MaxCount;
	}

	void AddItem(class CItem* Item)
	{
		// m_Count는 0부터 시작이다. 첫번째 아이템이 들어온다면 0번 인덱스에
		// 생성된 아이템의 주소를 넣어둔다.
		m_Item[m_Count] = Item;
		++m_Count;
	}

public:
	bool Init();
	void Run();
};

