#include "ObjectManager.h"
#include "Player.h"
#include "Monster.h"

CObjectManager* CObjectManager::m_Inst = nullptr;

CObjectManager::CObjectManager()	:
	m_Player(nullptr),
	m_Monster{}
{
}

CObjectManager::~CObjectManager()
{
	// 동적할당된 플레이어를 메모리에서 해제한다.
	SAFE_DELETE(m_Player);

	for(int i = 0; i < 3; ++i)
	{
		SAFE_DELETE(m_Monster[i]);
	}

	// p 대신에 m_Player를 넣어서 코드를 여기에 붙여준다.
	// if(p) { delete p; p = nullptr; }
	// if (m_Player) { delete m_Player; m_Player = nullptr; }
	//delete	m_Player;
}

CObjectManager* CObjectManager::GetInst()
{
	if (m_Inst == nullptr)
		m_Inst = new CObjectManager;

	return m_Inst;
}

void CObjectManager::DestroyInst()
{
	// m_Inst에 객체가 할당되어 있을때만 제거한다.
	if (m_Inst != nullptr)
	{
		delete	m_Inst;
		m_Inst = nullptr;
	}
}

bool CObjectManager::Init()
{
	// 플레이어를 생성한다.
	m_Player = new CPlayer;

	if (!m_Player->Init())
		return false;

	m_Monster[0] = new CMonster;
	m_Monster[0]->Init("고블린", 30, 10, 100, 10, 1, 1000, 1000);

	m_Monster[1] = new CMonster;
	m_Monster[1]->Init("오크", 80, 50, 900, 100, 5, 5000, 5000);

	m_Monster[2] = new CMonster;
	m_Monster[2]->Init("드래곤", 300, 100, 5000, 1000, 10, 20000, 20000);

	return true;
}

CMonster* CObjectManager::CreateMonster(EBattleMenu Battle)
{
	switch (Battle)
	{
	case EBattleMenu::Easy:
		return m_Monster[0]->Clone();
	case EBattleMenu::Normal:
		return m_Monster[1]->Clone();
	case EBattleMenu::Hard:
		return m_Monster[2]->Clone();
	}

	return nullptr;
}
