#include "Monster.h"

CMonster::CMonster() :
	m_Name{},
	m_Attack(0),
	m_Armor(0),
	m_HP(0),
	m_HPMax(0),
	m_MP(0),
	m_MPMax(0),
	m_Level(1),
	m_Exp(0),
	m_Gold(0)
{
}

CMonster::CMonster(const CMonster& monster)
{
	// 모든 멤버변수들을 그대로 복사해준다. 얕은복사를 수행한다.
	// this는 자기 자신이고 앞에 *을 붙여 역참조를 하여 생성되는 객체에 인자로 들어온 몬스터의
	// 모든 멤버변수를 그대로 복사해준다.
	*this = monster;
}

CMonster::~CMonster()
{
}

bool CMonster::Init(const char* Name, int Attack, int Armor, int HP, int MP, int Level,
	int Exp, int Gold)
{
	strcpy_s(m_Name, Name);
	m_Attack = Attack;
	m_Armor = Armor;
	m_HP = HP;
	m_HPMax = HP;
	m_MP = MP;
	m_MPMax = MP;
	m_Level = Level;
	m_Exp = Exp;
	m_Gold = Gold;

	return true;
}

void CMonster::Output()
{
	std::cout << "이름 : " << m_Name << std::endl;
	std::cout << "레벨 : " << m_Level << "\t획득경험치 : " << m_Exp << std::endl;
	std::cout << "공격력 : " << m_Attack << "\t방어력 : " << m_Armor << std::endl;
	std::cout << "체력 : " << m_HP << " / " << m_HPMax << "\t마나 : " << m_MP <<
		" / " << m_MPMax << std::endl;
	std::cout << "획득돈 : " << m_Gold << std::endl;
}

CMonster* CMonster::Clone()
{
	// new CMonster를 해서 새로운 Monster클래의 객체를 생성한다.
	// 단, 복사생성자를 호출해주는데 이 함수를 호출한 객체를 그대로 전달해주어서 이 함수를 호출
	// 한 객체를 복제한 새로운 몬스터 객체를 만들어서 반환한다.
	return new CMonster(*this);
}
