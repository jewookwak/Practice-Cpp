#pragma once

#include "GameInfo.h"

class CObjectManager
{
private:
	CObjectManager();
	~CObjectManager();

private:
	static CObjectManager* m_Inst;

public:
	// cpp�� �����κ��� ������ְ��� �ϴ� �Լ��� ���ó���ؼ� Ctrl + . �� ���� �Ŀ� c(����/����)��
	// ������ cpp�� �ڵ����� �Լ��� �����κ��� ������ش�.
	static CObjectManager* GetInst();
	static void DestroyInst();

private:
	class CPlayer* m_Player;
	class CMonster* m_Monster[3];

public:
	// ����Լ��� �ڿ� const�� �ٿ��ָ� �� �Լ������� ��������� ���� ������ �� ����.
	// �׸��� const ��ü�� �� �Լ��� ȣ���� �� �ְ� �ȴ�.
	class CPlayer* GetPlayer()	const
	{
		return m_Player;
	}

public:
	bool Init();
	// ���̵��� ���� ���͸� �����ؼ� ��ȯ���ش�.
	CMonster* CreateMonster(EBattleMenu Battle);
};

