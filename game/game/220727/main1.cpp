
#include "GameManager.h"

int main()
{
	// �����Ϸ��� ������ �Ҷ� TestNumber ��ſ� #define�� ���ǵ� 10�� ���⿡ �ٿ��־��ش�.
	//std::cout << TestNumber << std::endl;
	//TestOutput

	// GetInst�� ������ ��ü�� Init�Լ��� ȣ���Ͽ� ��ü ������ �ʱ�ȭ�Ѵ�.
	if (CGameManager::GetInst()->Init() == false)
	{
		// �ʱ�ȭ�� �����ߴٸ� GetInst�� ������ ��ü�� �����ְ� ������ �����Ѵ�.
		CGameManager::DestroyInst();
		return 0;
	}

	// ������ ���۽�Ų��.
	CGameManager::GetInst()->Run();

	// ���� ���� ������ �ݵ�� �޸𸮸� �����ؾ� �Ѵ�.
	CGameManager::DestroyInst();

	return 0;
}
