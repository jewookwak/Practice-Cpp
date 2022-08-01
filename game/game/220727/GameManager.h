#pragma once

#include "GameInfo.h"

enum class EMainMenu
{
	None,
	Battle,
	Store,
	Inventory,
	Exit
};

/*
���������� : ���� ����ϴ� Ŭ���� ����� ����ȭ�س��� ���̴�.

�̱��� : ��ü ������ N����ŭ �����ϴ� ����̴�.
��ü ������ 1���� ������ �� �ֵ��� �����ϴ� ����̴�.
å���� ���� �� ������ �ٸ��� ����Ǿ� �ִ� ��쵵 �ִ�.
���� 1�� �����ؼ� ����Ҷ� �ַ� ����Ѵ�.

static����� Ư¡�� �̿��ؼ� ��ü ������ �����Ѵ�.
*/


class CGameManager
{
	/*
	�����ڿ� �Ҹ��ڰ� private�̶�� Ŭ������ �ܺο����� ȣ���� �Ұ����ϴ�.
	��, ��ü�� �����Ҷ� ������ �����ڰ� �ڵ����� ȣ���� �Ǵµ� private�̶�� �� Ŭ������
	�ܺο����� �����ڸ� ȣ���� �� ���� �Ǿ� ��ü�� �ܺο��� �����ϴ°��� �Ұ����ϴ�.
	*/
private:
	CGameManager();
	~CGameManager();

private:
	static CGameManager* m_Inst;

public:
	// cpp�� �����κ��� ������ְ��� �ϴ� �Լ��� ���ó���ؼ� Ctrl + . �� ���� �Ŀ� c(����/����)��
	// ������ cpp�� �ڵ����� �Լ��� �����κ��� ������ش�.
	static CGameManager* GetInst();
	static void DestroyInst();

	// �ܺο��� ȣ��� �ʿ䰡 ���� �Լ��� ��� private���� �س��� ����Ѵ�.
private:
	EMainMenu Menu();

public:
	bool Init();
	void Run();
};

