#pragma once

#include "GameInfo.h"

class CPlayer
{
public:
	CPlayer();
	~CPlayer();

private:
	char	m_Name[32];
	EJob	m_Job;
	int		m_Attack;
	int		m_Armor;
	int		m_HP;
	int		m_HPMax;
	int		m_MP;
	int		m_MPMax;
	int		m_Level;
	int		m_Exp;
	int		m_Gold;

public:
	int GetAttack()
	{
		return m_Attack;
	}

	int GetArmor()
	{
		return m_Armor;
	}

	int GetHP()
	{
		return m_HP;
	}

	int GetMP()
	{
		return m_MP;
	}

	int GetGold()
	{
		return m_Gold;
	}

	void AddGold(int Gold)
	{
		m_Gold += Gold;
	}

	void AddExp(int Exp)
	{
		m_Exp += Exp;
	}

	// 죽었는지 살았는지를 판단하기 위해 bool 타입으로 리턴을 한다.
	bool Damage(int Dmg)
	{
		m_HP -= Dmg;

		// 죽었을 경우 true를 반환한다.
		if (m_HP <= 0)
		{
			m_HP = 0;
			return true;
		}

		return false;
	}

	void Resurrection()
	{
		m_HP = m_HPMax;
		m_MP = m_MPMax;

		// 경험치와 돈을 10% 만큼 감소시킨다.
		m_Exp = (int)(m_Exp * 0.9f);
		m_Gold = (int)(m_Gold * 0.9f);
	}

public:
	bool Init();
	void Output();
};

