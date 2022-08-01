#pragma once

#include "GameInfo.h"

// 전방선언 : 여기에 어떤 클래스가 있다 라고 가정을 하고 해당 타입의 포인터 변수를
// 선언해 놓을 수 있게 해준다. include 없이.
// 단, 실제 할당을 하고 그 객체를 이용해서 멤버함수를 호출한다던지 하는 사용 행위는
// 불가능하다.
class CBattle;
class CBattleManager
{
private:
	CBattleManager();
	~CBattleManager();

private:
	static CBattleManager* m_Inst;

public:
	// cpp에 구현부분을 만들어주고자 하는 함수를 블록처리해서 Ctrl + . 을 누른 후에 c(선언/정의)를
	// 누르면 cpp에 자동으로 함수의 구현부분을 만들어준다.
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

