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
	// �̸��� �Է¹޴´�.
	std::cout << "�̸��� �Է��ϼ��� : ";
	std::cin >> m_Name;

	// ������ �����Ѵ�.
	while (true)
	{
		std::cout << "1. ���" << std::endl;
		std::cout << "2. �ü�" << std::endl;
		std::cout << "3. ������" << std::endl;
		std::cout << "4. ����" << std::endl;

		std::cout << "������ �����ϼ��� : ";
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

	// ���õ� ������ ���� ������ �����Ѵ�.
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
	std::cout << "�̸� : " << m_Name << "\t���� : ";
	
	switch (m_Job)
	{
	case EJob::Knight:
		std::cout << "���" << std::endl;
		break;
	case EJob::Archer:
		std::cout << "�ü�" << std::endl;
		break;
	case EJob::Magicion:
		std::cout << "������" << std::endl;
		break;
	}
	std::cout << "���� : " << m_Level << "\t����ġ : " << m_Exp << std::endl;
	std::cout << "���ݷ� : " << m_Attack << "\t���� : " << m_Armor << std::endl;
	std::cout << "ü�� : " << m_HP << " / " << m_HPMax << "\t���� : " << m_MP <<
		" / " << m_MPMax << std::endl;
	std::cout << "�� : " << m_Gold << std::endl;
}
