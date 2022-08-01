#include "StoreManager.h"
#include "Store.h"

CStoreManager* CStoreManager::m_Inst = nullptr;

CStoreManager::CStoreManager()	:
	m_Store(nullptr)
{
}

CStoreManager::~CStoreManager()
{
	SAFE_DELETE_ARRAY(m_Store);
}

CStoreManager* CStoreManager::GetInst()
{
	if (m_Inst == nullptr)
		m_Inst = new CStoreManager;

	return m_Inst;
}

void CStoreManager::DestroyInst()
{
	// m_Inst에 객체가 할당되어 있을때만 제거한다.
	if (m_Inst != nullptr)
	{
		delete	m_Inst;
		m_Inst = nullptr;
	}
}

EStoreMenu CStoreManager::Menu()
{
	// 화면을 지워준다.
	system("cls");

	std::cout << "1. 무기상점" << std::endl;
	std::cout << "2. 방어구상점" << std::endl;
	std::cout << "3. 뒤로가기" << std::endl;
	std::cout << "메뉴를 선택하세요 : ";
	int	Select;

	std::cin >> Select;

	if (Select <= (int)EStoreMenu::None || Select > (int)EStoreMenu::Back)
		return EStoreMenu::None;

	return (EStoreMenu)Select;
}

bool CStoreManager::Init()
{
	m_Store = new CStore[(int)EStoreMenu::Back - 1];

	const char* FileName[2] = { "StoreWeapon.txt", "StoreArmor.txt" };

	for (int i = 0; i < (int)EStoreMenu::Back - 1; ++i)
	{
		m_Store[i].Init((EStoreMenu)(i + 1), FileName[i]);
	}

	return true;
}

void CStoreManager::Run()
{
	while (true)
	{
		switch (Menu())
		{
		case EStoreMenu::Weapon:
			m_Store[0].Run();
			break;
		case EStoreMenu::Armor:
			m_Store[1].Run();
			break;
		case EStoreMenu::Back:
			return;
		}
	}
}
