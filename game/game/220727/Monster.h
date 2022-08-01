#pragma once

#include "GameInfo.h"

class CMonster
{
public:
	CMonster();
	// 몬스터를 복제하기 위해 복사생성자를 만든다.
	CMonster(const CMonster& monster);
	~CMonster();

private:
	char	m_Name[32];
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

	int GetExp()
	{
		return m_Exp;
	}

	int GetGold()
	{
		return m_Gold;
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

public:
	bool Init(const char* Name, int Attack, int Armor, int HP, int MP, int Level,
		int Exp, int Gold);
	void Output();
	CMonster* Clone();
};

