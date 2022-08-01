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
	// m_Inst�� ��ü�� �Ҵ�Ǿ� �������� �����Ѵ�.
	if (m_Inst != nullptr)
	{
		delete	m_Inst;
		m_Inst = nullptr;
	}
}

EStoreMenu CStoreManager::Menu()
{
	// ȭ���� �����ش�.
	system("cls");

	std::cout << "1. �������" << std::endl;
	std::cout << "2. ������" << std::endl;
	std::cout << "3. �ڷΰ���" << std::endl;
	std::cout << "�޴��� �����ϼ��� : ";
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
