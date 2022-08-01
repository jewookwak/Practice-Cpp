#include "Store.h"
#include "Item.h"
#include "ObjectManager.h"
#include "Player.h"
#include "Inventory.h"

CStore::CStore()	:
	m_Item(nullptr),
	m_ItemCount(0)
{
}

CStore::~CStore()
{
	SAFE_DELETE_ARRAY(m_Item);
}

bool CStore::Init(EStoreMenu Type, const char* FileName)
{
	m_StoreType = Type;

	// ������ �о �Ǹ��� �����۵��� �������ش�.
	std::ifstream	stream(FileName);

	if (stream.fail())
		return false;

	// �ϳ��� �о�´�.
	stream >> m_ItemCount;

	// �������� ������ŭ �迭�� �Ҵ��Ѵ�.
	m_Item = new CItem[m_ItemCount];

	for (int i = 0; i < m_ItemCount; ++i)
	{
		char	Name[32] = {};
		int	ItemType = 0, Option = 0, Price = 0, Sell = 0;

		stream >> Name;
		stream >> ItemType;
		stream >> Option;
		stream >> Price;
		stream >> Sell;

		m_Item[i].Init(Name, (EItemType)ItemType, Option, Price, Sell);
	}

	stream.close();

	return true;
}

void CStore::Run()
{
	// �÷��̾ ���´�.
	CPlayer* Player = CObjectManager::GetInst()->GetPlayer();

	while (true)
	{
		system("cls");
		switch (m_StoreType)
		{
		case EStoreMenu::Weapon:
			std::cout << "====================== ������� ======================" << std::endl;
			break;
		case EStoreMenu::Armor:
			std::cout << "====================== ������ ======================" << std::endl;
			break;
		}

		// ���� ������ �������� ����Ѵ�.
		for (int i = 0; i < m_ItemCount; ++i)
		{
			std::cout << i + 1 << ". ";
			m_Item[i].Output();
			std::cout << std::endl;
		}

		std::cout << m_ItemCount + 1 << ". �ڷΰ���" << std::endl;
		std::cout << "�����ݾ� : " << Player->GetGold() << std::endl;
		std::cout << "������ �������� �����ϼ��� : ";
		int	Select;

		std::cin >> Select;

		if (Select == m_ItemCount + 1)
			return;

		else if (Select < 1 || Select > m_ItemCount + 1)
			continue;

		// 1���� �޴��� �����̹Ƿ� 1�� ���� �ε����� ������ش�.
		int	ItemIndex = Select - 1;

		// �κ��丮�� �� á�ų� �ݾ��� ������ ��� �������� ������ �� ����.
		if (CInventory::GetInst()->IsFull())
		{
			std::cout << "�κ��丮�� ������ �����մϴ�." << std::endl;

			// Ű�� ���������� �Ͻ����� ���ش�.
			system("pause");
			continue;
		}

		else if (Player->GetGold() < m_Item[ItemIndex].GetPrice())
		{
			std::cout << "�����ݾ��� �����մϴ�." << std::endl;

			// Ű�� ���������� �Ͻ����� ���ش�.
			system("pause");
			continue;
		}

		// �������� �����ϸ� �ݾ��� �����ϰ� �������� �Ǹ��ϴ� ������ �ϳ��� �����ؼ� �κ��丮��
		// �־��ش�.
		CItem* Item = m_Item[ItemIndex].Clone();

		// ���� �����Ѵ�.
		Player->AddGold(-Item->GetPrice());

		CInventory::GetInst()->AddItem(Item);
	}
}
