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

	//���Ŀ� �ۼ��غ���
	//void SetFullScreen();
	//void SetFontSize();
};

