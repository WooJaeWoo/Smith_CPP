// BattleShip_Class.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	char a, b;
	std::cout << "Alphabet: ";
	std::cin >> a;
	std::cout << "Number: ";
	std::cin >> b;
	srand(time(NULL));
	std::string strResults[] = { "HIT", "MISS", "DESTROY" };
	std::cout << strResults[rand() % (sizeof(strResults) / sizeof(strResults[0]))] << std::endl;
	return 0;
}

