#include "Player.h"

CPlayer::CPlayer()	:
	m_Name{},
	m_Job(EJob::None),
	m_Attack(0),
	m_Armor(0),
	m_HP(0),
	m_HPMax(0),
	m_MP(0),
	m_MPMax(0),
	m_Level(1),
	m_Exp(0),
	m_Gold(0)
{
}

CPlayer::~CPlayer()
{
}

bool CPlayer::Init()
{
	// 이름을 입력받는다.
	std::cout << "이름을 입력하세요 : ";
	std::cin >> m_Name;

	// 직업을 선택한다.
	while (true)
	{
		std::cout << "1. 기사" << std::endl;
		std::cout << "2. 궁수" << std::endl;
		std::cout << "3. 마법사" << std::endl;
		std::cout << "4. 종료" << std::endl;

		std::cout << "직업을 선택하세요 : ";
		int	Select;
		std::cin >> Select;

		if (Select == 4)
			return false;

		else if (Select >= 1 && Select <= 3)
		{
			m_Job = (EJob)Select;
			break;
		}
	}

	// 선택된 직업에 따라 정보를 설정한다.
	switch (m_Job)
	{
	case EJob::Knight:
		m_Attack = 20;
		m_Armor = 20;
		m_HP = 500;
		m_HPMax = 500;
		m_MP = 100;
		m_MPMax = 100;
		break;
	case EJob::Archer:
		m_Attack = 30;
		m_Armor = 15;
		m_HP = 400;
		m_HPMax = 400;
		m_MP = 200;
		m_MPMax = 200;
		break;
	case EJob::Magicion:
		m_Attack = 40;
		m_Armor = 10;
		m_HP = 300;
		m_HPMax = 300;
		m_MP = 300;
		m_MPMax = 300;
		break;
	}

	m_Level = 1;
	m_Exp = 0;
	m_Gold = 10000;

	return true;
}

void CPlayer::Output()
{
	std::cout << "이름 : " << m_Name << "\t직업 : ";
	
	switch (m_Job)
	{
	case EJob::Knight:
		std::cout << "기사" << std::endl;
		break;
	case EJob::Archer:
		std::cout << "궁수" << std::endl;
		break;
	case EJob::Magicion:
		std::cout << "마법사" << std::endl;
		break;
	}
	std::cout << "레벨 : " << m_Level << "\t경험치 : " << m_Exp << std::endl;
	std::cout << "공격력 : " << m_Attack << "\t방어력 : " << m_Armor << std::endl;
	std::cout << "체력 : " << m_HP << " / " << m_HPMax << "\t마나 : " << m_MP <<
		" / " << m_MPMax << std::endl;
	std::cout << "돈 : " << m_Gold << std::endl;
}
