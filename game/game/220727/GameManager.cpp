#include "GameManager.h"
#include "BattleManager.h"
#include "ObjectManager.h"
#include "StoreManager.h"
#include "Inventory.h"

CGameManager* CGameManager::m_Inst = nullptr;

// 클래스의 멤버 함수는 반환타입 클래스명::함수() 의 형태로 구현부분에 작성한다.
CGameManager::CGameManager()
{
}

CGameManager::~CGameManager()
{
	// 게임이 종료될때 전투관리자도 메모리에서 해제해주어야 한다.
	CBattleManager::DestroyInst();

	// 게임이 종료될때 오브젝트 관리자도 메모리에서 해제해주어야 한다.
	CObjectManager::DestroyInst();

	// 게임이 종료될때 상점 관리자도 메모리에서 해제해주어야 한다.
	CStoreManager::DestroyInst();

	// 게임이 종료될때 인벤토리도 메모리에서 해제해주어야 한다.
	CInventory::DestroyInst();
}

/*
이 함수를 통해서 CGameManager의 객체를 생성할 수 있다.
단, 한번 생성하면 그 주소를 그대로 계속 리턴만 하게 된다.
객체가 1개만 만들어진다는 것이다.
*/
CGameManager* CGameManager::GetInst()
{
	// 여기는 CGameManager 클래스의 내부이다.
	// 그러므로 CGameManager의 private에 접근이 가능하다.
	if (m_Inst == nullptr)
		m_Inst = new CGameManager;

	return m_Inst;
}

void CGameManager::DestroyInst()
{
	// m_Inst에 객체가 할당되어 있을때만 제거한다.
	if (m_Inst != nullptr)
	{
		delete	m_Inst;
		m_Inst = nullptr;
	}
}

EMainMenu CGameManager::Menu()
{
	// 화면을 지워준다.
	system("cls");

	std::cout << "1. 전투" << std::endl;
	std::cout << "2. 상점" << std::endl;
	std::cout << "3. 인벤토리" << std::endl;
	std::cout << "4. 종료" << std::endl;
	std::cout << "메뉴를 선택하세요 : ";
	int	Select;

	std::cin >> Select;

	if (Select <= (int)EMainMenu::None || Select > (int)EMainMenu::Exit)
		return EMainMenu::None;

	return (EMainMenu)Select;
}

bool CGameManager::Init()
{
	// 전투관리자를 초기화한다.
	if (CBattleManager::GetInst()->Init() == false)
		return false;

	// 오브젝트 관리자를 초기화한다.
	if (!CObjectManager::GetInst()->Init())
		return false;

	// 상잠 관리자를 초기화한다.
	if (!CStoreManager::GetInst()->Init())
		return false;

	// 인벤토리를 초기화한다.
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
