#include "Inventory.h"
#include "Item.h"

CInventory* CInventory::m_Inst = nullptr;

CInventory::CInventory()	:
	m_MaxCount(10),
	m_Count(0),
	m_Item(nullptr)
{
}

CInventory::~CInventory()
{
	// 실제 인벤토리에 추가된 아이템 수만큼 반복하며 동적할당한 아이템을
	// 메모리에서 제거한다.
	for (int i = 0; i < m_Count; ++i)
	{
		SAFE_DELETE(m_Item[i]);
	}

	// 동적배열로 할당한 포인터 배열을 제거한다.
	SAFE_DELETE_ARRAY(m_Item);
}

CInventory* CInventory::GetInst()
{
	if (m_Inst == nullptr)
		m_Inst = new CInventory;

	return m_Inst;
}

void CInventory::DestroyInst()
{
	// m_Inst에 객체가 할당되어 있을때만 제거한다.
	if (m_Inst != nullptr)
	{
		delete	m_Inst;
		m_Inst = nullptr;
	}
}

bool CInventory::Init()
{
	// 아이템 포인터 배열을 선언한다.
	// 각 배열의 요소는 포인터를 저장할 수 있다.
	// 동적할당된 아이템 주소를 여기에 저장해두는 것이다.
	// 즉, 배열의 각 요소는 동적할당된 아이템의 메모리 주소가 저장되므로 반드시 제거해야 한다.
	m_Item = new CItem * [m_MaxCount];

	return true;
}

void CInventory::Run()
{
	while (true)
	{
		system("cls");
		
		std::cout << "=================== 인벤토리 ===================" << std::endl;

		for (int i = 0; i < m_Count; ++i)
		{
			std::cout << i + 1 << ". ";
			m_Item[i]->Output();
			std::cout << std::endl;
		}

		std::cout << m_Count + 1 << ". 뒤로가기" << std::endl;
		std::cout << "장착할 아이템을 선택하세요 : ";
		int	Select;
		std::cin >> Select;

		if (Select == m_Count + 1)
			return;

		else if (Select < 1 || Select > m_Count + 1)
			continue;
	}
}
