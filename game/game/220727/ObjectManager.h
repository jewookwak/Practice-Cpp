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
	// cpp에 구현부분을 만들어주고자 하는 함수를 블록처리해서 Ctrl + . 을 누른 후에 c(선언/정의)를
	// 누르면 cpp에 자동으로 함수의 구현부분을 만들어준다.
	static CObjectManager* GetInst();
	static void DestroyInst();

private:
	class CPlayer* m_Player;
	class CMonster* m_Monster[3];

public:
	// 멤버함수의 뒤에 const를 붙여주면 이 함수에서는 멤버변수의 값을 변경할 수 없다.
	// 그리고 const 객체가 이 함수를 호출할 수 있게 된다.
	class CPlayer* GetPlayer()	const
	{
		return m_Player;
	}

public:
	bool Init();
	// 난이도에 따른 몬스터를 생성해서 반환해준다.
	CMonster* CreateMonster(EBattleMenu Battle);
};

