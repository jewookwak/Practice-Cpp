#include "BattleManager.h"
#include "Battle.h"

CBattleManager* CBattleManager::m_Inst = nullptr;

CBattleManager::CBattleManager()	:
	m_Battle(nullptr)
{
}

CBattleManager::~CBattleManager()
{
	// 동적 배열로 할당한 메모리 주소를 가지고 있으므로 반드시 메모리 해제를 한다.
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
	// m_Inst에 객체가 할당되어 있을때만 제거한다.
	if (m_Inst != nullptr)
	{
		delete	m_Inst;
		m_Inst = nullptr;
	}
}

EBattleMenu CBattleManager::Menu()
{
	// 화면을 지워준다.
	system("cls");

	std::cout << "1. 쉬움" << std::endl;
	std::cout << "2. 보통" << std::endl;
	std::cout << "3. 어려움" << std::endl;
	std::cout << "4. 뒤로가기" << std::endl;
	std::cout << "메뉴를 선택하세요 : ";
	int	Select;

	std::cin >> Select;

	if (Select <= (int)EBattleMenu::None || Select > (int)EBattleMenu::Back)
		return EBattleMenu::None;

	return (EBattleMenu)Select;
}

bool CBattleManager::Init()
{
	// 3개의 난이도별 Battle을 만들어둔다.
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
