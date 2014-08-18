#pragma once
#include <windows.h>
#include "HeaderSet.h"

class GameRender
{
public:
	GameRender();
	~GameRender();

	void SetTitle() { SetConsoleTitle(L"Smith's Battleship Game"); }
	void SetConsoleSize(int widht, int height);
	void SetFontColor(Colors color);

	//추후에 작성해보기
	//void SetFullScreen();
	//void SetFontSize();
};

