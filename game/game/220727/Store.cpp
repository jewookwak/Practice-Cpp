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

	// 파일을 읽어서 판매할 아이템들을 생성해준다.
	std::ifstream	stream(FileName);

	if (stream.fail())
		return false;

	// 하나씩 읽어온다.
	stream >> m_ItemCount;

	// 아이템을 개수만큼 배열로 할당한다.
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
	// 플레이어를 얻어온다.
	CPlayer* Player = CObjectManager::GetInst()->GetPlayer();

	while (true)
	{
		system("cls");
		switch (m_StoreType)
		{
		case EStoreMenu::Weapon:
			std::cout << "====================== 무기상점 ======================" << std::endl;
			break;
		case EStoreMenu::Armor:
			std::cout << "====================== 방어구상점 ======================" << std::endl;
			break;
		}

		// 구매 가능한 아이템을 출력한다.
		for (int i = 0; i < m_ItemCount; ++i)
		{
			std::cout << i + 1 << ". ";
			m_Item[i].Output();
			std::cout << std::endl;
		}

		std::cout << m_ItemCount + 1 << ". 뒤로가기" << std::endl;
		std::cout << "보유금액 : " << Player->GetGold() << std::endl;
		std::cout << "구매할 아이템을 선택하세요 : ";
		int	Select;

		std::cin >> Select;

		if (Select == m_ItemCount + 1)
			return;

		else if (Select < 1 || Select > m_ItemCount + 1)
			continue;

		// 1부터 메뉴가 시작이므로 1을 빼서 인덱스로 만들어준다.
		int	ItemIndex = Select - 1;

		// 인벤토리가 꽉 찼거나 금액이 부족할 경우 아이템을 구매할 수 없다.
		if (CInventory::GetInst()->IsFull())
		{
			std::cout << "인벤토리에 공간이 부족합니다." << std::endl;

			// 키를 누를때까지 일시정지 해준다.
			system("pause");
			continue;
		}

		else if (Player->GetGold() < m_Item[ItemIndex].GetPrice())
		{
			std::cout << "보유금액이 부족합니다." << std::endl;

			// 키를 누를때까지 일시정지 해준다.
			system("pause");
			continue;
		}

		// 아이템을 구매하면 금액을 차감하고 상점에서 판매하는 아이템 하나를 복제해서 인벤토리에
		// 넣어준다.
		CItem* Item = m_Item[ItemIndex].Clone();

		// 돈을 차감한다.
		Player->AddGold(-Item->GetPrice());

		CInventory::GetInst()->AddItem(Item);
	}
}
