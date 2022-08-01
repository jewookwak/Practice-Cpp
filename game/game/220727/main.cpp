
#include <iostream>


class CItem1
{
public:
	CItem1()
	{
		m_Array = new int[10];
	}

	/*
	��������� : ���ڸ� const Ŭ����Ÿ��& �� ���� �����ڸ� ���Ѵ�.
	��������ڴ� Ŭ������ �̿��ؼ� ��ü�� �����Ҷ� �ٸ� ��ü�� ���� �״�� �����ؼ� �����Ǵ�
	��ü�� ���鶧 ����Ѵ�.
	�ַ� �������̳� ���� ���� Ŭ�������� ���� Ȱ���� �� �� �ִ�.
	�������� ��� ���͸� ��Ƽ� ���� �������� ���� �������� ������ �����ؼ� ������ ��ü��
	����߸��� ���ϰ� �۾��� �� �ֱ� �����̴�.

	���� ����� 2���� ����� �ִ�.
	���� ����, ���� ���� 2�����̴�.
	���� ����� �ܼ��� ������ �����Ѵ�.
	���� ����� �����Ҵ�� �޸��ּҸ� Ŭ���� ����� ������ ���� ���
	����ɶ� ���� ������ ������ �����Ҵ��� ���ְ� �� �ּҸ� ���� �� �ְ� ���ش�.
	*/
	CItem1(const CItem1& item)
	{
		strcpy_s(m_Name, item.m_Name);
		m_Attack = item.m_Attack;
		m_Price = item.m_Price;

		// ��������
		//m_Array = item.m_Array;

		// ��������
		m_Array = new int[10];

		memcpy(m_Array, item.m_Array, sizeof(int) * 10);
	}

	~CItem1()
	{
		delete[]	m_Array;
	}

public:
	char	m_Name[32];
	int		m_Attack;
	int		m_Price;

	int* m_Array;
};

/*
Ŭ������ static ��������� static ����Լ�
static ������� : �ݵ�� Ŭ���� �ܺο� ���� �ʱ�ȭ �κ��� �߰��ؾ� �Ѵ�.
static��������� �� Ŭ������ �̿��ؼ� ��ü�� �ƹ��� ���� �����ϴ��� ��� ��ü��
�����ϴ� �޸� �� 1���� ��������� �ȴ�.

static ����Լ� : static ����Լ������� this�� ����. ��, �Ϲ� ��������� ������ �� ����
static ��������� ���� �����ϴ�.
*/
class CStatic
{
public:
	CStatic()
	{
	}

	~CStatic()
	{
	}

public:
	int	m_A;
	static int m_B;

public:
	void Output()
	{
		std::cout << "A : " << m_A << std::endl;
		std::cout << "B : " << m_B << std::endl;
	}

	// �Ʒ� �Լ� �ȿ����� this�� ����� �� ����. �׷��Ƿ� �Ϲ� ��������� ������ �Ұ����ϴ�.
	static void OutputStatic()
	{
		//std::cout << "A : " << m_A << std::endl;
		std::cout << "B : " << m_B << std::endl;
	}
};

// static ��������� ����κ��� ������ Ŭ������ �ܺο� �ʿ��ϴ�.
int CStatic::m_B = 0;


int main()
{
	// ������ ������ �ִ� ���� ������
	CItem1	OriginItem;

	strcpy_s(OriginItem.m_Name, "������");
	OriginItem.m_Attack = 10;
	OriginItem.m_Price = 450;

	// ������ ���Ž� ������ ���� �������� �����ؼ� ������.
	// Item ��ü�� �����Ѵ�. �̶� ���� �������� OriginItem�� ���ڷ� �Ѱ��־
	// ����������� ���ڿ� ������������ �����ϴ� ���̴�.
	CItem1	Item(OriginItem);

	std::cout << "�̸� : " << Item.m_Name << std::endl;
	std::cout << "���ݷ� : " << Item.m_Attack << std::endl;
	std::cout << "���� : " << Item.m_Price << std::endl;

	CStatic	st1, st2, st3;

	st1.m_A = 100;
	st2.m_A = 200;
	st3.m_A = 300;

	st1.m_B = 100;
	st2.m_B = 200;
	st3.m_B = 300;
	CStatic::m_B = 400;

	std::cout << "st1 A : " << st1.m_A << std::endl;
	std::cout << "st2 A : " << st2.m_A << std::endl;
	std::cout << "st3 A : " << st3.m_A << std::endl;

	std::cout << "st1 B : " << st1.m_B << std::endl;
	std::cout << "st2 B : " << st2.m_B << std::endl;
	std::cout << "st3 B : " << st3.m_B << std::endl;

	st1.OutputStatic();
	CStatic::OutputStatic();

	return 0;
}
