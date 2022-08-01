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
	// �����Ҵ�� �÷��̾ �޸𸮿��� �����Ѵ�.
	SAFE_DELETE(m_Player);

	for(int i = 0; i < 3; ++i)
	{
		SAFE_DELETE(m_Monster[i]);
	}

	// p ��ſ� m_Player�� �־ �ڵ带 ���⿡ �ٿ��ش�.
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
	// m_Inst�� ��ü�� �Ҵ�Ǿ� �������� �����Ѵ�.
	if (m_Inst != nullptr)
	{
		delete	m_Inst;
		m_Inst = nullptr;
	}
}

bool CObjectManager::Init()
{
	// �÷��̾ �����Ѵ�.
	m_Player = new CPlayer;

	if (!m_Player->Init())
		return false;

	m_Monster[0] = new CMonster;
	m_Monster[0]->Init("���", 30, 10, 100, 10, 1, 1000, 1000);

	m_Monster[1] = new CMonster;
	m_Monster[1]->Init("��ũ", 80, 50, 900, 100, 5, 5000, 5000);

	m_Monster[2] = new CMonster;
	m_Monster[2]->Init("�巡��", 300, 100, 5000, 1000, 10, 20000, 20000);

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
