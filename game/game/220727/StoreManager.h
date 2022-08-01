#pragma once

#include "GameInfo.h"

class CStoreManager
{
private:
	CStoreManager();
	~CStoreManager();

private:
	static CStoreManager* m_Inst;

public:
	// cpp�� �����κ��� ������ְ��� �ϴ� �Լ��� ���ó���ؼ� Ctrl + . �� ���� �Ŀ� c(����/����)��
	// ������ cpp�� �ڵ����� �Լ��� �����κ��� ������ش�.
	static CStoreManager* GetInst();
	static void DestroyInst();

private:
	EStoreMenu Menu();

private:
	class CStore* m_Store;

public:
	bool Init();
	void Run();
};

