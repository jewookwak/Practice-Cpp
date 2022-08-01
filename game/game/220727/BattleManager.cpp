#include "BattleManager.h"
#include "Battle.h"

CBattleManager* CBattleManager::m_Inst = nullptr;

CBattleManager::CBattleManager()	:
	m_Battle(nullptr)
{
}

CBattleManager::~CBattleManager()
{
	// ���� �迭�� �Ҵ��� �޸� �ּҸ� ������ �����Ƿ� �ݵ�� �޸� ������ �Ѵ�.
	delete[]	m_Battle;
}

CBattleManager* CBattleManager::GetInst()
{
	if (m_Inst == nullptr)
		m_Inst = new CBattleManager;

	return m_Inst;
}

void CBattleManager::DestroyInst()
{
	// m_Inst�� ��ü�� �Ҵ�Ǿ� �������� �����Ѵ�.
	if (m_Inst != nullptr)
	{
		delete	m_Inst;
		m_Inst = nullptr;
	}
}

EBattleMenu CBattleManager::Menu()
{
	// ȭ���� �����ش�.
	system("cls");

	std::cout << "1. ����" << std::endl;
	std::cout << "2. ����" << std::endl;
	std::cout << "3. �����" << std::endl;
	std::cout << "4. �ڷΰ���" << std::endl;
	std::cout << "�޴��� �����ϼ��� : ";
	int	Select;

	std::cin >> Select;

	if (Select <= (int)EBattleMenu::None || Select > (int)EBattleMenu::Back)
		return EBattleMenu::None;

	return (EBattleMenu)Select;
}

bool CBattleManager::Init()
{
	// 3���� ���̵��� Battle�� �����д�.
	m_Battle = new CBattle[3];

	m_Battle[0].SetBattleMenu(EBattleMenu::Easy);
	m_Battle[1].SetBattleMenu(EBattleMenu::Normal);
	m_Battle[2].SetBattleMenu(EBattleMenu::Hard);

	for (int i = 0; i < 3; ++i)
	{
		if (m_Battle[i].Init() == false)
			return false;
	}

	return true;
}

void CBattleManager::Run()
{
	while (true)
	{
		switch (Menu())
		{
		case EBattleMenu::Easy:
			m_Battle[0].Run();
			break;
		case EBattleMenu::Normal:
			m_Battle[1].Run();
			break;
		case EBattleMenu::Hard:
			m_Battle[2].Run();
			break;
		case EBattleMenu::Back:
			return;
		}
	}
}
