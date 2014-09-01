// Battleship_Smith.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
#include "stdafx.h"
#include "GameEngine.h"
#include "GameManager.h"
#include "Map.h"

int _tmain(int argc, _TCHAR* argv[])
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	srand((unsigned)time(NULL));

 	GameEngine* gameEngine = new GameEngine();
 	gameEngine->GameRun();
 	delete gameEngine;


	
	GameManager* gm1 = new GameManager();
	Map* map1 = new Map(8);
	
	gm1->GamePlayPage(*map1, *map1);
	gm1->AttakInterface();
	gm1->RenderWin();
	delete gm1;
	delete map1;

	getchar();
	return 0;
}