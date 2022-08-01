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

	void Resurrection()
	{
		m_HP = m_HPMax;
		m_MP = m_MPMax;

		// ����ġ�� ���� 10% ��ŭ ���ҽ�Ų��.
		m_Exp = (int)(m_Exp * 0.9f);
		m_Gold = (int)(m_Gold * 0.9f);
	}

public:
	bool Init();
	void Output();
};

