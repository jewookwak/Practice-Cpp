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
	// ���� �κ��丮�� �߰��� ������ ����ŭ �ݺ��ϸ� �����Ҵ��� ��������
	// �޸𸮿��� �����Ѵ�.
	for (int i = 0; i < m_Count; ++i)
	{
		SAFE_DELETE(m_Item[i]);
	}

	// �����迭�� �Ҵ��� ������ �迭�� �����Ѵ�.
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
	// m_Inst�� ��ü�� �Ҵ�Ǿ� �������� �����Ѵ�.
	if (m_Inst != nullptr)
	{
		delete	m_Inst;
		m_Inst = nullptr;
	}
}

bool CInventory::Init()
{
	// ������ ������ �迭�� �����Ѵ�.
	// �� �迭�� ��Ҵ� �����͸� ������ �� �ִ�.
	// �����Ҵ�� ������ �ּҸ� ���⿡ �����صδ� ���̴�.
	// ��, �迭�� �� ��Ҵ� �����Ҵ�� �������� �޸� �ּҰ� ����ǹǷ� �ݵ�� �����ؾ� �Ѵ�.
	m_Item = new CItem * [m_MaxCount];

	return true;
}

void CInventory::Run()
{
	while (true)
	{
		system("cls");
		
		std::cout << "=================== �κ��丮 ===================" << std::endl;

		for (int i = 0; i < m_Count; ++i)
		{
			std::cout << i + 1 << ". ";
			m_Item[i]->Output();
			std::cout << std::endl;
		}

		std::cout << m_Count + 1 << ". �ڷΰ���" << std::endl;
		std::cout << "������ �������� �����ϼ��� : ";
		int	Select;
		std::cin >> Select;

		if (Select == m_Count + 1)
			return;

		else if (Select < 1 || Select > m_Count + 1)
			continue;
	}
}
