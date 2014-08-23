#pragma once
#include <windows.h>
#include "HeaderSet.h"

class GameRender
{
public:
	GameRender();
	~GameRender();

	void SetWindowTitle() { SetConsoleTitle(L"Smith's Battleship Game"); }
	void RenderTitle();
	void PlayerSettingPage();
	void GameSettingPage();

	void GotoXY(int x, int y);
	void SetConsoleSize(int widht, int height);
	void SetColor(int fcolor, int bcolor);
};