#pragma once

#include "GameInfo.h"

class CBattle
{
public:
	CBattle();
	~CBattle();

private:
	EBattleMenu	m_BattleMenu;

public:
	void SetBattleMenu(EBattleMenu Battle)
	{
		m_BattleMenu = Battle;
	}

	EBattleMenu GetBattle()	const
	{
		return m_BattleMenu;
	}

public:
	bool Init();
	void Run();
};

