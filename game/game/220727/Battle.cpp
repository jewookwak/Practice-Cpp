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
	// ������Ʈ �Ŵ������� ������� �÷��̾ ���⿡�� ���ͼ� ����� �Ѵ�.
	CPlayer* Player = CObjectManager::GetInst()->GetPlayer();

	// ���� ���̵��� �´� ���͸� �ϳ� �����ؼ� �����Ͽ� ���⿡ �����´�.
	CMonster* Monster = CObjectManager::GetInst()->CreateMonster(m_BattleMenu);

	while (true)
	{
		system("cls");

		switch (m_BattleMenu)
		{
		case EBattleMenu::Easy:
			std::cout << "======================= ���� =======================" << std::endl;
			break;
		case EBattleMenu::Normal:
			std::cout << "======================= ���� =======================" << std::endl;
			break;
		case EBattleMenu::Hard:
			std::cout << "======================= ����� =======================" << std::endl;
			break;
		}

		// �÷��̾ ����Ѵ�.
		Player->Output();

		std::cout << std::endl;

		// ���͸� ����Ѵ�.
		Monster->Output();

		std::cout << std::endl;

		std::cout << "1. ����" << std::endl;
		std::cout << "2. ��������" << std::endl;
		std::cout << "�޴��� �����ϼ��� : ";
		int	Select;
		std::cin >> Select;

		if (Select == 2)
		{
			// ���ʹ� new�� �ؼ� �����ؼ� ������ ���̹Ƿ� ������ ������ �ݵ�� delete�� ���־�� �Ѵ�.
			SAFE_DELETE(Monster);
			return;
		}

		// �߸��� ���ڸ� �Է����� ��� �ٽ� �Է¹ް� �Ѵ�.
		else if (Select < 1 || Select > 2)
			continue;

		// ������ �����Ѵ�.
		// �÷��̾ ���͸� �����Ѵ�. ���� �������� ���ݷ� - ������ �̿��Ͽ� �������� ����Ѵ�.
		int	Damage = Player->GetAttack() - Monster->GetArmor();

		// ���׿����� : ���ǽ� ? true�϶���ȯ�� : false�϶���ȯ�� ���� ����.
		// �ּ� ������ 1�� �ش�.
		Damage = Damage < 1 ? 1 : Damage;

		// Monster���� Damage�� �ش�. return�� true�� �Ǹ� ���Ͱ� �׾��ٴ� �ǹ��̴�.
		if (Monster->Damage(Damage))
		{
			// �÷��̾�� ������ ����ġ�� ���� ���������ش�.
			Player->AddExp(Monster->GetExp());
			Player->AddGold(Monster->GetGold());

			// �������� �ߴ��� üũ�Ѵ�.


			// ���Ͱ� �׾����Ƿ� ����� �ٽ� �������ش�.
			SAFE_DELETE(Monster);

			Monster = CObjectManager::GetInst()->CreateMonster(m_BattleMenu);

			// �ٽ� ���������Ƿ� ���Ӱ� ������ �� �� �ְ� ���ش�.
			continue;
		}

		// ���Ͱ� �÷��̾ �����Ѵ�.
		Damage = Monster->GetAttack() - Player->GetArmor();

		Damage = Damage < 1 ? 1 : Damage;

		// true�� ��ȯ�Ǹ� �÷��̾ �׾��ٴ� ���̴�.
		if (Player->Damage(Damage))
		{
			Player->Resurrection();
		}
	}
}
