#include "stdafx.h"
#include "GameRender.h"


GameRender::GameRender()
{
}


GameRender::~GameRender()
{
}

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void GameRender::SetConsoleSize(int width, int height)
{
	//작은 사이즈
	//SMALL_RECT windowSize = { 0, 0, width - 1, height - 1 };
	//SetConsoleWindowInfo(hConsole, TRUE, &windowSize);
	
	//큰 사이즈는 이걸로 가능
	//system("mode con:cols=100 lines=50");
}

void GameRender::SetFontColor(Colors color)
{
	SetConsoleTextAttribute(hConsole, color);
	std::cout << "Color Test" << std::endl;

	//	forecolor, backgroundcolor 이용하는 방법
	// 	int color = 4;
	// 	int bgcolor;
	// 	color &= 0xf;
	// 	bgcolor &= 0xf;
	// 	SetConsoleTextAttribute(hConsole, (bgcolor << 4) | color);
}

// void GameRender::SetFontSize()
// {
// 	CONSOLE_FONT_INFOEX font;
// 	GetCurrentConsoleFontEx(hConsole, FALSE, &font);
// 	font.dwFontSize.X = 5;
// 	font.dwFontSize.Y = 2;
// 	SetCurrentConsoleFontEx(hConsole, FALSE, &font);
// 	std::cout << "abc" << std::endl;
// }

// void GameRender::SetFullScreen()
// {
// 	CONSOLE_SCREEN_BUFFER_INFO info;
// 	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
// 	SMALL_RECT rc;
// 	rc.Left = rc.Top = 0;
// 	rc.Right = (short)(min(info.dwMaximumWindowSize.X, info.dwSize.X) - 1);
// 	rc.Bottom = (short)(min(info.dwMaximumWindowSize.Y, info.dwSize.Y) - 1);
// 	SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), true, &rc);
// }
