// Battleship_Smith.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
#include "stdafx.h"
#include "HeaderSet.h"
#include "GameRender.h"


int _tmain(int argc, _TCHAR* argv[])
{
	srand((unsigned)time(NULL));

	GameRender gr1;
	gr1.SetWindowTitle();
	gr1.RenderTitle();
	gr1.PlayerSettingPage();
	gr1.GameSettingPage();
//	getchar();
	return 0;
}