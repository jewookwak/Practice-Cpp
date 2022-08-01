#include "Battle.h"
#include "Player.h"
#include "Monster.h"
#include "ObjectManager.h"

CBattle::CBattle()
{
}

CBattle::~CBattle()
{
}

bool CBattle::Init()
{
	return true;
}

void CBattle::Run()
{
	// 오브젝트 매니저에서 만들어준 플레이어를 여기에서 얻어와서 사용을 한다.
	CPlayer* Player = CObjectManager::GetInst()->GetPlayer();

	// 현재 난이도에 맞는 몬스터를 하나 복제해서 생성하여 여기에 가져온다.
	CMonster* Monster = CObjectManager::GetInst()->CreateMonster(m_BattleMenu);

	while (true)
	{
		system("cls");

		switch (m_BattleMenu)
		{
		case EBattleMenu::Easy:
			std::cout << "======================= 쉬움 =======================" << std::endl;
			break;
		case EBattleMenu::Normal:
			std::cout << "======================= 보통 =======================" << std::endl;
			break;
		case EBattleMenu::Hard:
			std::cout << "======================= 어려움 =======================" << std::endl;
			break;
		}

		// 플레이어를 출력한다.
		Player->Output();

		std::cout << std::endl;

		// 몬스터를 출력한다.
		Monster->Output();

		std::cout << std::endl;

		std::cout << "1. 공격" << std::endl;
		std::cout << "2. 도망가기" << std::endl;
		std::cout << "메뉴를 선택하세요 : ";
		int	Select;
		std::cin >> Select;

		if (Select == 2)
		{
			// 몬스터는 new를 해서 생성해서 가져온 것이므로 전투가 끝나면 반드시 delete를 해주어야 한다.
			SAFE_DELETE(Monster);
			return;
		}

		// 잘못된 숫자를 입력했을 경우 다시 입력받게 한다.
		else if (Select < 1 || Select > 2)
			continue;

		// 전투를 진행한다.
		// 플레이어가 몬스터를 공격한다. 공격 데미지는 공격력 - 방어력을 이용하여 데미지를 계산한다.
		int	Damage = Player->GetAttack() - Monster->GetArmor();

		// 삼항연산자 : 조건식 ? true일때반환값 : false일때반환값 으로 쓴다.
		// 최소 데미지 1로 준다.
		Damage = Damage < 1 ? 1 : Damage;

		// Monster에게 Damage를 준다. return이 true가 되면 몬스터가 죽었다는 의미이다.
		if (Monster->Damage(Damage))
		{
			// 플레이어에게 몬스터의 경험치와 돈을 누적시켜준다.
			Player->AddExp(Monster->GetExp());
			Player->AddGold(Monster->GetGold());

			// 레벨업을 했는지 체크한다.


			// 몬스터가 죽었으므로 지우고 다시 생성해준다.
			SAFE_DELETE(Monster);

			Monster = CObjectManager::GetInst()->CreateMonster(m_BattleMenu);

			// 다시 생성했으므로 새롭게 전투를 할 수 있게 해준다.
			continue;
		}

		// 몬스터가 플레이어를 공격한다.
		Damage = Monster->GetAttack() - Player->GetArmor();

		Damage = Damage < 1 ? 1 : Damage;

		// true가 반환되면 플레이어가 죽었다는 것이다.
		if (Player->Damage(Damage))
		{
			Player->Resurrection();
		}
	}
}
