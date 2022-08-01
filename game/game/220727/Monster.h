#pragma once

#include "GameInfo.h"

class CMonster
{
public:
	CMonster();
	// ���͸� �����ϱ� ���� ��������ڸ� �����.
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

	// �׾����� ��Ҵ����� �Ǵ��ϱ� ���� bool Ÿ������ ������ �Ѵ�.
	bool Damage(int Dmg)
	{
		m_HP -= Dmg;

		// �׾��� ��� true�� ��ȯ�Ѵ�.
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

