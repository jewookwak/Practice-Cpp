#include "GameManager.h"
#include "BattleManager.h"
#include "ObjectManager.h"
#include "StoreManager.h"
#include "Inventory.h"

CGameManager* CGameManager::m_Inst = nullptr;

// Ŭ������ ��� �Լ��� ��ȯŸ�� Ŭ������::�Լ�() �� ���·� �����κп� �ۼ��Ѵ�.
CGameManager::CGameManager()
{
}

CGameManager::~CGameManager()
{
	// ������ ����ɶ� ���������ڵ� �޸𸮿��� �������־�� �Ѵ�.
	CBattleManager::DestroyInst();

	// ������ ����ɶ� ������Ʈ �����ڵ� �޸𸮿��� �������־�� �Ѵ�.
	CObjectManager::DestroyInst();

	// ������ ����ɶ� ���� �����ڵ� �޸𸮿��� �������־�� �Ѵ�.
	CStoreManager::DestroyInst();

	// ������ ����ɶ� �κ��丮�� �޸𸮿��� �������־�� �Ѵ�.
	CInventory::DestroyInst();
}

/*
�� �Լ��� ���ؼ� CGameManager�� ��ü�� ������ �� �ִ�.
��, �ѹ� �����ϸ� �� �ּҸ� �״�� ��� ���ϸ� �ϰ� �ȴ�.
��ü�� 1���� ��������ٴ� ���̴�.
*/
CGameManager* CGameManager::GetInst()
{
	// ����� CGameManager Ŭ������ �����̴�.
	// �׷��Ƿ� CGameManager�� private�� ������ �����ϴ�.
	if (m_Inst == nullptr)
		m_Inst = new CGameManager;

	return m_Inst;
}

void CGameManager::DestroyInst()
{
	// m_Inst�� ��ü�� �Ҵ�Ǿ� �������� �����Ѵ�.
	if (m_Inst != nullptr)
	{
		delete	m_Inst;
		m_Inst = nullptr;
	}
}

EMainMenu CGameManager::Menu()
{
	// ȭ���� �����ش�.
	system("cls");

	std::cout << "1. ����" << std::endl;
	std::cout << "2. ����" << std::endl;
	std::cout << "3. �κ��丮" << std::endl;
	std::cout << "4. ����" << std::endl;
	std::cout << "�޴��� �����ϼ��� : ";
	int	Select;

	std::cin >> Select;

	if (Select <= (int)EMainMenu::None || Select > (int)EMainMenu::Exit)
		return EMainMenu::None;

	return (EMainMenu)Select;
}

bool CGameManager::Init()
{
	// ���������ڸ� �ʱ�ȭ�Ѵ�.
	if (CBattleManager::GetInst()->Init() == false)
		return false;

	// ������Ʈ �����ڸ� �ʱ�ȭ�Ѵ�.
	if (!CObjectManager::GetInst()->Init())
		return false;

	// ���� �����ڸ� �ʱ�ȭ�Ѵ�.
	if (!CStoreManager::GetInst()->Init())
		return false;

	// �κ��丮�� �ʱ�ȭ�Ѵ�.
	if (!CInventory::GetInst()->Init())
		return false;

	return true;
}

void CGameManager::Run()
{
	while (true)
	{
		switch (Menu())
		{
		case EMainMenu::Battle:
			CBattleManager::GetInst()->Run();
			break;
		case EMainMenu::Store:
			CStoreManager::GetInst()->Run();
			break;
		case EMainMenu::Inventory:
			CInventory::GetInst()->Run();
			break;
		case EMainMenu::Exit:
			return;
		}
	}
}
