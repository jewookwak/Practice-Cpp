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
	// cpp�� �����κ��� ������ְ��� �ϴ� �Լ��� ���ó���ؼ� Ctrl + . �� ���� �Ŀ� c(����/����)��
	// ������ cpp�� �ڵ����� �Լ��� �����κ��� ������ش�.
	static CInventory* GetInst();
	static void DestroyInst();

private:
	// ���������ͷ� ������ ������ ������ �����迭�� ������ֱ� ���ؼ��̴�.
	class CItem** m_Item;
	int		m_Count;	// ���� �κ��丮�� �߰��� ����.
	int		m_MaxCount;	// �κ��丮�� �������� �߰��� �� �ִ� �ִ� ����

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
		// m_Count�� 0���� �����̴�. ù��° �������� ���´ٸ� 0�� �ε�����
		// ������ �������� �ּҸ� �־�д�.
		m_Item[m_Count] = Item;
		++m_Count;
	}

public:
	bool Init();
	void Run();
};

