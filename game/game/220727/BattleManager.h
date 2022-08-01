#pragma once

#include "GameInfo.h"

// ���漱�� : ���⿡ � Ŭ������ �ִ� ��� ������ �ϰ� �ش� Ÿ���� ������ ������
// ������ ���� �� �ְ� ���ش�. include ����.
// ��, ���� �Ҵ��� �ϰ� �� ��ü�� �̿��ؼ� ����Լ��� ȣ���Ѵٴ��� �ϴ� ��� ������
// �Ұ����ϴ�.
class CBattle;
class CBattleManager
{
private:
	CBattleManager();
	~CBattleManager();

private:
	static CBattleManager* m_Inst;

public:
	// cpp�� �����κ��� ������ְ��� �ϴ� �Լ��� ���ó���ؼ� Ctrl + . �� ���� �Ŀ� c(����/����)��
	// ������ cpp�� �ڵ����� �Լ��� �����κ��� ������ش�.
	static CBattleManager* GetInst();
	static void DestroyInst();

private:
	CBattle* m_Battle;

private:
	EBattleMenu Menu();

public:
	bool Init();
	void Run();
};

