
#include <iostream>


class CItem1
{
public:
	CItem1()
	{
		m_Array = new int[10];
	}

	/*
	복사생성자 : 인자를 const 클래스타입& 로 갖는 생성자를 말한다.
	복사생성자는 클래스를 이용해서 객체를 생성할때 다른 객체의 값을 그대로 복사해서 생성되는
	객체를 만들때 사용한다.
	주로 아이템이나 몬스터 같은 클래스에서 많이 활용을 할 수 있다.
	아이템의 경우 몬스터를 잡아서 땅에 떨어질때 원본 아이템의 정보를 복사해서 생성한 객체를
	떨어뜨리면 편하게 작업할 수 있기 때문이다.

	복사 방식은 2가지 방식이 있다.
	얕은 복사, 깊은 복사 2가지이다.
	얕은 복사는 단순히 값만을 복사한다.
	깊은 복사는 동적할당된 메모리주소를 클래스 멤버로 가지고 있을 경우
	복사될때 실제 공간을 별도로 동적할당을 해주고 그 주소를 가질 수 있게 해준다.
	*/
	CItem1(const CItem1& item)
	{
		strcpy_s(m_Name, item.m_Name);
		m_Attack = item.m_Attack;
		m_Price = item.m_Price;

		// 얕은복사
		//m_Array = item.m_Array;

		// 깊은복사
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
클래스의 static 멤버변수와 static 멤버함수
static 멤버변수 : 반드시 클래스 외부에 변수 초기화 부분을 추가해야 한다.
static멤버변수는 이 클래스를 이용해서 객체를 아무리 많이 생성하더라도 모든 객체가
공유하는 메모리 딱 1개만 만들어지게 된다.

static 멤버함수 : static 멤버함수에서는 this가 없다. 즉, 일반 멤버변수는 접근할 수 없고
static 멤버변수만 접근 가능하다.
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

	// 아래 함수 안에서는 this를 사용할 수 없다. 그러므로 일반 멤버변수는 접근이 불가능하다.
	static void OutputStatic()
	{
		//std::cout << "A : " << m_A << std::endl;
		std::cout << "B : " << m_B << std::endl;
	}
};

// static 멤버변수는 선언부분이 별도로 클래스의 외부에 필요하다.
int CStatic::m_B = 0;


int main()
{
	// 상점이 가지고 있는 원본 아이템
	CItem1	OriginItem;

	strcpy_s(OriginItem.m_Name, "도란검");
	OriginItem.m_Attack = 10;
	OriginItem.m_Price = 450;

	// 아이템 구매시 상점의 원본 아이템을 복제해서 만들어낸다.
	// Item 객체를 생성한다. 이때 원본 아이템은 OriginItem을 인자로 넘겨주어서
	// 복사생성자의 인자에 원본아이템을 전달하는 것이다.
	CItem1	Item(OriginItem);

	std::cout << "이름 : " << Item.m_Name << std::endl;
	std::cout << "공격력 : " << Item.m_Attack << std::endl;
	std::cout << "가격 : " << Item.m_Price << std::endl;

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
