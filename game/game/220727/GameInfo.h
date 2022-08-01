#pragma once

#include <iostream>
#include <fstream>

/*
전처리기이다. TestNumber를 코드 중간에 사용하면 뒤의 10이라는 코드를 그곳에 복사해준다.
반드시 한줄로 작성해야 한다.
단, 디버깅이 안된다. 너무 많이 쓰면 안좋다.
*/
#define	TestNumber	10
#define	TestOutput std::cout << "TestOutput" << std::endl;

// p가 포인터변수가 들어오고 메모리주소가 있을 경우 delete를 해주고 nullptr로 초기화해준다.
#define	SAFE_DELETE(p)	if(p) { delete p; p = nullptr; }
#define	SAFE_DELETE_ARRAY(p)	if(p) { delete[] p; p = nullptr; }


enum class EBattleMenu : unsigned char
{
	None,
	Easy,
	Normal,
	Hard,
	Back
};

enum class EJob : unsigned char
{
	None,
	Knight,
	Archer,
	Magicion
};

enum class EStoreMenu : unsigned char
{
	None,
	Weapon,
	Armor,
	Back
};

enum class EItemType : unsigned char
{
	Weapon,
	Armor
};
