// BattleShip_Class.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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

