#include "stdafx.h"
#include "GameRender.h"
#include <conio.h>

GameRender::GameRender()
{
}


GameRender::~GameRender()
{
}

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

//RENDERINT SCREEN FUNCTIONS
void GameRender::RenderTitle()
{
	system("cls");
	SetColor(BLACK, WHITE);
	system("mode con:cols=83 lines=12");
	printf_s("                                                                                  \n");
	printf_s("  ■■■     ■  ■■■■ ■■■■ ■     ■■■  ■■■ ■    ■ ■■■ ■■■   \n");
	printf_s("  ■   ■   ■■    ■       ■    ■     ■     ■      ■    ■   ■   ■   ■  \n");
	printf_s("  ■■■   ■  ■   ■       ■    ■     ■■■  ■■   ■■■■   ■   ■■■   \n");
	printf_s("  ■   ■ ■■■■  ■       ■    ■     ■          ■ ■    ■   ■   ■       \n");
	printf_s("  ■■■  ■    ■  ■       ■    ■■■ ■■■ ■■■  ■    ■ ■■■ ■       \n");
	printf_s("                                                                                  \n");
	SetColor(GRAY, BLACK);
	printf_s("\n  SMITH GAMES \t\t\t\t\t\t\t\t   ver1.0\n");
	SetColor(WHITE, BLACK);
	while (!_kbhit())
	{
		Sleep(600);
		GotoXY(0, 10);
		printf_s("\t\t\t     PRESS ENTER KEY TO START      \t\t\t");
		Sleep(1000);
		GotoXY(0, 10);
		printf_s("                                                                                        ");
	}
	getchar();
}


void GameRender::PlayerSettingPage()
{
	system("mode con:cols=62 lines=27");
	system("cls");
	SetColor(BLACK, WHITE);
	printf_s("                                                             \n");
	printf_s("   ■■■ ■■■ ■■■■ ■■■■ ■■■ ■    ■   ■■■  \n");
	printf_s("  ■      ■        ■       ■      ■   ■■  ■  ■    ■ \n");
	printf_s("   ■■   ■■■    ■       ■      ■   ■ ■ ■ ■        \n");
	printf_s("       ■ ■        ■       ■      ■   ■  ■■  ■  ■■ \n");
	printf_s("  ■■■  ■■■    ■       ■    ■■■ ■    ■   ■■ ■ \n");
	printf_s("                                                             \n");
	int gotoX = 23;
	int gotoY = 9;
	GotoXY(gotoX - 1, gotoY);
	printf_s("                  \n");
	GotoXY(gotoX - 1, gotoY + 1);
	printf_s("   PLAYER SELECT  \n");
	GotoXY(gotoX - 1, gotoY + 2);
	printf_s("                  ");
	SetColor(WHITE, BLACK);
	GotoXY(gotoX + 6, gotoY + 6);
	printf_s("VS Friend");
	GotoXY(gotoX + 6, gotoY + 9);
	printf_s("VS AI");
	GotoXY(gotoX + 6, gotoY + 12);
	printf_s("VS Network");
	int currentPositionY = gotoY + 6;
	int playerSellect = 1;
	GotoXY(gotoX, currentPositionY);
	printf_s("▶");
	while (true)
	{
		GotoXY(60, 26);
		int keyinput;
		keyinput = _getch();
		if (keyinput == -32)
		{
			keyinput = _getch();
		}
		if (keyinput == KEY_DOWN)
		{
			if (playerSellect == 1 || playerSellect == 2)
			{
				GotoXY(gotoX, currentPositionY);
				printf_s("  ");
				currentPositionY += 3;
				playerSellect += 1;
				GotoXY(gotoX, currentPositionY);
				printf_s("▶");
			}
		}
		else if (keyinput == KEY_UP)
		{
			if (playerSellect == 2 || playerSellect == 3)
			{
				GotoXY(gotoX, currentPositionY);
				printf_s("  ");
				currentPositionY -= 3;
				playerSellect -= 1;
				GotoXY(gotoX, currentPositionY);
				printf_s("▶");
			}
		}
		else if (keyinput == ENTER)
		{
			//Pass the value in playerSellect to GameSetting class
			break;
		}
	}
}

void GameRender::GameSettingPage()
{
	system("mode con:cols=62 lines=32");
	system("cls");
	SetColor(BLACK, WHITE);
	printf_s("                                                             \n");
	printf_s("   ■■■ ■■■ ■■■■ ■■■■ ■■■ ■    ■   ■■■  \n");
	printf_s("  ■      ■        ■       ■      ■   ■■  ■  ■    ■ \n");
	printf_s("   ■■   ■■■    ■       ■      ■   ■ ■ ■ ■        \n");
	printf_s("       ■ ■        ■       ■      ■   ■  ■■  ■  ■■ \n");
	printf_s("  ■■■  ■■■    ■       ■    ■■■ ■    ■   ■■ ■ \n");
	printf_s("                                                             \n");
	int gotoX = 4;
	int gotoY = 9;

	//주의!!! 하드코딩
	//나중에 게임 이닛 코드에서 get하는 방식으로 다시 코딩하기!!!! 꼭!!!
	int numShip[] = { 1, 1, 1, 2};

	GotoXY(gotoX + 18, gotoY);
	printf_s("                  \n");
	GotoXY(gotoX + 18, gotoY + 1);
	printf_s("    SHIP SELECT   \n");
	GotoXY(gotoX + 18, gotoY + 2);
	printf_s("                  ");
	SetColor(WHITE, BLACK);
	GotoXY(gotoX + 6, gotoY + 5);
	printf_s("Aircraft Carrier");
	GotoXY(gotoX + 6, gotoY + 8);
	printf_s("Battleship");
	GotoXY(gotoX + 6, gotoY + 11);
	printf_s("Cruiser");
	GotoXY(gotoX + 6, gotoY + 14);
	printf_s("Destroyer");
	SetColor(BLACK, WHITE);
	GotoXY(gotoX + 18, gotoY + 17);
	printf_s("                   \n");
	GotoXY(gotoX + 18, gotoY + 18);
	printf_s("     GAME START    \n");
	GotoXY(gotoX + 18, gotoY + 19);
	printf_s("                   ");
	SetColor(WHITE, BLACK);
	GotoXY(gotoX + 39, gotoY + 5);
	int shipSellect = 0;
	printf_s("◀  %d  ▶", numShip[0]);
	GotoXY(gotoX + 39, gotoY + 8);
	printf_s("◀  %d  ▶", numShip[1]);
	GotoXY(gotoX + 39, gotoY + 11);
	printf_s("◀  %d  ▶", numShip[2]);
	GotoXY(gotoX + 39, gotoY + 14);
	printf_s("◀  %d  ▶", numShip[3]);
	int currentPositionY = gotoY + 5;
	GotoXY(gotoX, currentPositionY);
	printf_s("▶");
	while (true)
	{
		GotoXY(60, 26);
		int sumShips = 0;
		for (int i = 0; i < 4; i++)
		{
			sumShips += numShip[i];
		}
		int keyinput;
		keyinput = _getch();
		if (keyinput == -32)
		{
			keyinput = _getch();
		}
		if (keyinput == KEY_DOWN)
		{
			if (shipSellect == 0 || shipSellect == 1 || shipSellect == 2)
			{
				GotoXY(gotoX, currentPositionY);
				printf_s("  ");
				currentPositionY += 3;
				shipSellect += 1;
				GotoXY(gotoX, currentPositionY);
				printf_s("▶");
			}
			else if (shipSellect == 3)
			{
				GotoXY(gotoX, currentPositionY);
				printf_s("  ");
				currentPositionY += 3;
				shipSellect += 1;
				if (sumShips == 0)
					SetColor(BLACK, RED);
				else
					SetColor(BLACK, GREEN);
				GotoXY(gotoX + 18, gotoY + 17);
				printf_s("                   \n");
				GotoXY(gotoX + 18, gotoY + 18);
				printf_s("     GAME START    \n");
				GotoXY(gotoX + 18, gotoY + 19);
				printf_s("                   ");
			}
		}
		else if (keyinput == KEY_UP)
		{
			if (shipSellect == 1 || shipSellect == 2 || shipSellect == 3)
			{
				GotoXY(gotoX, currentPositionY);
				printf_s("  ");
				currentPositionY -= 3;
				shipSellect -= 1;
				GotoXY(gotoX, currentPositionY);
				printf_s("▶");
			}
			else if (shipSellect == 4)
			{
				currentPositionY -= 3;
				shipSellect -= 1;
				SetColor(BLACK, WHITE);
				GotoXY(gotoX + 18, gotoY + 17);
				printf_s("                   \n");
				GotoXY(gotoX + 18, gotoY + 18);
				printf_s("     GAME START    \n");
				GotoXY(gotoX + 18, gotoY + 19);
				printf_s("                   ");
				SetColor(WHITE, BLACK);
				GotoXY(gotoX, currentPositionY);
				printf_s("▶");
			}
		}
		else if (keyinput == KEY_LEFT)
		{
			if (numShip[shipSellect] > 0)
			{
				if (shipSellect == 0 || shipSellect == 1 || shipSellect == 2 || shipSellect == 3)
				{
					numShip[shipSellect] -= 1;
					GotoXY(gotoX + 39, currentPositionY);
					printf_s("◀  %d  ▶", numShip[shipSellect]);
				}
			}
		}
		else if (keyinput == KEY_RIGHT)
		{
			if (numShip[shipSellect] < 3)
			{
				if (shipSellect == 0 || shipSellect == 1 || shipSellect == 2 || shipSellect == 3)
				{
					numShip[shipSellect] += 1;
					GotoXY(gotoX + 39, currentPositionY);
					printf_s("◀  %d  ▶", numShip[shipSellect]);
				}
			}
		}
		else if (keyinput == ENTER)
		{
			//Pass the value in playerSellect to GameSetting class
			break;
		}
	}
}


//SET CONSOLE FUNCTIONS
void GameRender::GotoXY(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void GameRender::SetColor(int fcolor, int bcolor)
{
	fcolor &= 0xf;
	bcolor &= 0xf;
	SetConsoleTextAttribute(hConsole, (bcolor << 4) | fcolor);
}

void GameRender::SetConsoleSize(int width, int height)
{
	system("mode con:cols=100 lines=50");
}