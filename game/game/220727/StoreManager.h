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
	// cpp에 구현부분을 만들어주고자 하는 함수를 블록처리해서 Ctrl + . 을 누른 후에 c(선언/정의)를
	// 누르면 cpp에 자동으로 함수의 구현부분을 만들어준다.
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

