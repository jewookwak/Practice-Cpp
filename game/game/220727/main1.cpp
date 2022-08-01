
#include "GameManager.h"

int main()
{
	// 컴파일러가 컴파일 할때 TestNumber 대신에 #define에 정의된 10을 여기에 붙여넣어준다.
	//std::cout << TestNumber << std::endl;
	//TestOutput

	// GetInst로 생성된 객체의 Init함수를 호출하여 전체 게임을 초기화한다.
	if (CGameManager::GetInst()->Init() == false)
	{
		// 초기화가 실패했다면 GetInst로 생성한 객체를 지워주고 게임을 종료한다.
		CGameManager::DestroyInst();
		return 0;
	}

	// 게임을 동작시킨다.
	CGameManager::GetInst()->Run();

	// 게임 종료 직전에 반드시 메모리를 제거해야 한다.
	CGameManager::DestroyInst();

	return 0;
}
