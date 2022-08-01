#pragma once

#include <iostream>
#include <fstream>

/*
��ó�����̴�. TestNumber�� �ڵ� �߰��� ����ϸ� ���� 10�̶�� �ڵ带 �װ��� �������ش�.
�ݵ�� ���ٷ� �ۼ��ؾ� �Ѵ�.
��, ������� �ȵȴ�. �ʹ� ���� ���� ������.
*/
#define	TestNumber	10
#define	TestOutput std::cout << "TestOutput" << std::endl;

// p�� �����ͺ����� ������ �޸��ּҰ� ���� ��� delete�� ���ְ� nullptr�� �ʱ�ȭ���ش�.
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
