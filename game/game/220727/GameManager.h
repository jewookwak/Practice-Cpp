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
디자인패턴 : 자주 사용하는 클래스 방식을 정형화해놓은 것이다.

싱글톤 : 객체 생성을 N개만큼 제한하는 방식이다.
객체 생성을 1개만 생성할 수 있도록 제한하는 방식이다.
책마다 위의 두 주제로 다르게 설명되어 있는 경우도 있다.
보통 1개 생성해서 사용할때 주로 사용한다.

static멤버의 특징을 이용해서 객체 생성을 제한한다.
*/


class CGameManager
{
	/*
	생성자와 소멸자가 private이라면 클래스의 외부에서는 호출이 불가능하다.
	즉, 객체를 생성할때 무조건 생성자가 자동으로 호출이 되는데 private이라면 이 클래스의
	외부에서는 생성자를 호출할 수 없게 되어 객체를 외부에서 생성하는것이 불가능하다.
	*/
private:
	CGameManager();
	~CGameManager();

private:
	static CGameManager* m_Inst;

public:
	// cpp에 구현부분을 만들어주고자 하는 함수를 블록처리해서 Ctrl + . 을 누른 후에 c(선언/정의)를
	// 누르면 cpp에 자동으로 함수의 구현부분을 만들어준다.
	static CGameManager* GetInst();
	static void DestroyInst();

	// 외부에서 호출될 필요가 없는 함수의 경우 private으로 해놓고 사용한다.
private:
	EMainMenu Menu();

public:
	bool Init();
	void Run();
};

