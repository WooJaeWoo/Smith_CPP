// Battleship_Smith.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//
#include "stdafx.h"
#include "GameManager.h"

int _tmain(int argc, _TCHAR* argv[])
{
	srand((unsigned)time(NULL));

	GameManager* gameManager = new GameManager();
	gameManager->GameRun();

	getchar();
	return 0;
}