#pragma once

#include "GameInfo.h"

class CStore
{
public:
	CStore();
	~CStore();

private:
	EStoreMenu	m_StoreType;
	class CItem* m_Item;
	int			m_ItemCount;

public:
	bool Init(EStoreMenu Type, const char* FileName);
	void Run();
};

