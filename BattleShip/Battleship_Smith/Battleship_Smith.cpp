// Battleship_Smith.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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