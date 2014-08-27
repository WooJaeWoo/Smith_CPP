#include "stdafx.h"
#include "GameRender.h"
#include "HeaderSet.h"
#include <conio.h>
#include "Map.h"

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
	SetConsoleSize(83, 12);
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

void GameRender::RenderPlayerSettingPage()
{
	SetConsoleSize(63, 27);
	system("cls");
	SetColor(BLACK, WHITE);
	printf_s("                                                              \n");
	printf_s("   ■■■ ■■■ ■■■■ ■■■■ ■■■ ■    ■   ■■■   \n");
	printf_s("  ■      ■        ■       ■      ■   ■■  ■  ■    ■  \n");
	printf_s("   ■■   ■■■    ■       ■      ■   ■ ■ ■ ■         \n");
	printf_s("       ■ ■        ■       ■      ■   ■  ■■  ■  ■■  \n");
	printf_s("  ■■■  ■■■    ■       ■    ■■■ ■    ■   ■■ ■  \n");
	printf_s("                                                              \n");
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
	int playerSellect = 0;
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
			if (playerSellect == 0 || playerSellect == 1)
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
			if (playerSellect == 1 || playerSellect == 2)
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
			if (playerSellect == 0)
			{
				m_PlayerType = NORMAL;
				break;
			}
			else if (playerSellect == 1)
			{
				m_PlayerType = AI;
				break;
			}
			else if (playerSellect == 2)
			{
				m_PlayerType = NETWORK;
				break;
			}
		}
	}
}

void GameRender::RenderGameSettingPage()
{
	SetConsoleSize(63, 34);
	system("cls");
	SetColor(BLACK, WHITE);
	printf_s("                                                              \n");
	printf_s("   ■■■ ■■■ ■■■■ ■■■■ ■■■ ■    ■   ■■■   \n");
	printf_s("  ■      ■        ■       ■      ■   ■■  ■  ■    ■  \n");
	printf_s("   ■■   ■■■    ■       ■      ■   ■ ■ ■ ■         \n");
	printf_s("       ■ ■        ■       ■      ■   ■  ■■  ■  ■■  \n");
	printf_s("  ■■■  ■■■    ■       ■    ■■■ ■    ■   ■■ ■  \n");
	printf_s("                                                              \n");
	int gotoX = 4;
	int gotoY = 9;

	GotoXY(gotoX + 18, gotoY);
	printf_s("                  \n");
	GotoXY(gotoX + 18, gotoY + 1);
	printf_s("    SHIP SELECT   \n");
	GotoXY(gotoX + 18, gotoY + 2);
	printf_s("                  ");
	SetColor(WHITE, BLACK);
	GotoXY(gotoX + 6, gotoY + 5);
	printf_s("Map size");
	GotoXY(gotoX + 6, gotoY + 8);
	printf_s("Aircraft Carrier");
	GotoXY(gotoX + 6, gotoY + 11);
	printf_s("Battleship");
	GotoXY(gotoX + 6, gotoY + 14);
	printf_s("Cruiser");
	GotoXY(gotoX + 6, gotoY + 17);
	printf_s("Destroyer");
	SetColor(BLACK, WHITE);
	GotoXY(gotoX + 18, gotoY + 20);
	printf_s("                   \n");
	GotoXY(gotoX + 18, gotoY + 21);
	printf_s("      N E X T      \n");
	GotoXY(gotoX + 18, gotoY + 22);
	printf_s("                   ");
	SetColor(WHITE, BLACK);
	int shipSellect = 0;
	m_MapSize = 8;
	GotoXY(gotoX + 40, gotoY + 5);
	printf_s("◀ %d*%d ▶", m_MapSize, m_MapSize);
	GotoXY(gotoX + 40, gotoY + 8);
	printf_s("◀  %d  ▶", m_NumShip[0]);
	GotoXY(gotoX + 40, gotoY + 11);
	printf_s("◀  %d  ▶", m_NumShip[1]);
	GotoXY(gotoX + 40, gotoY + 14);
	printf_s("◀  %d  ▶", m_NumShip[2]);
	GotoXY(gotoX + 40, gotoY + 17);
	printf_s("◀  %d  ▶", m_NumShip[3]);
	bool okToStart = false;
	int currentPositionY = gotoY + 5;
	GotoXY(gotoX, currentPositionY);
	printf_s("▶");
	while (true)
	{
		GotoXY(60, 30);
		int sumShips = 0;
		for (int i = 0; i < SHIPTYPECOUNT; i++)
		{
			sumShips += m_NumShip[i];
		}
		int keyinput;
		keyinput = _getch();
		if (keyinput == -32)
		{
			keyinput = _getch();
		}
		if (keyinput == KEY_DOWN)
		{
			if (shipSellect == 0 || shipSellect == 1 || shipSellect == 2 || shipSellect == 3)
			{
				GotoXY(gotoX, currentPositionY);
				printf_s("  ");
				currentPositionY += 3;
				shipSellect += 1;
				GotoXY(gotoX, currentPositionY);
				printf_s("▶");
			}
			else if (shipSellect == 4)
			{
				GotoXY(gotoX, currentPositionY);
				printf_s("  ");
				currentPositionY += 3;
				shipSellect += 1;
				if (sumShips == 0)
				{
					okToStart = false;
					SetColor(BLACK, DARK_RED);
					GotoXY(gotoX + 18, gotoY + 20);
					printf_s("                   \n");
					GotoXY(gotoX + 18, gotoY + 21);
					printf_s("      No Ship      \n");
					GotoXY(gotoX + 18, gotoY + 22);
					printf_s("                   ");
				}
				else if (ValidMapSize() == false)
				{
					okToStart = false;
					SetColor(BLACK, DARK_RED);
					GotoXY(gotoX + 18, gotoY + 20);
					printf_s("                   \n");
					GotoXY(gotoX + 18, gotoY + 21);
					printf_s("   Too Many Ships  \n");
					GotoXY(gotoX + 18, gotoY + 22);
					printf_s("                   ");
				}
				else
				{
					okToStart = true;
					SetColor(BLACK, GREEN);
					GotoXY(gotoX + 18, gotoY + 20);
					printf_s("                   \n");
					GotoXY(gotoX + 18, gotoY + 21);
					printf_s("      N E X T      \n");
					GotoXY(gotoX + 18, gotoY + 22);
					printf_s("                   ");
				}

			}
		}
		else if (keyinput == KEY_UP)
		{
			if (shipSellect == 1 || shipSellect == 2 || shipSellect == 3 || shipSellect == 4)
			{
				GotoXY(gotoX, currentPositionY);
				printf_s("  ");
				currentPositionY -= 3;
				shipSellect -= 1;
				GotoXY(gotoX, currentPositionY);
				printf_s("▶");
			}
			else if (shipSellect == 5)
			{
				currentPositionY -= 3;
				shipSellect -= 1;
				SetColor(BLACK, WHITE);
				GotoXY(gotoX + 18, gotoY + 20);
				printf_s("                   \n");
				GotoXY(gotoX + 18, gotoY + 21);
				printf_s("      N E X T      \n");
				GotoXY(gotoX + 18, gotoY + 22);
				printf_s("                   ");
				SetColor(WHITE, BLACK);
				GotoXY(gotoX, currentPositionY);
				printf_s("▶");
			}
		}
		else if (keyinput == KEY_LEFT)
		{
			if (shipSellect == 0)
			{
				if (m_MapSize > 5)
				{
					m_MapSize -= 1;
					GotoXY(gotoX + 40, currentPositionY);
					printf_s("◀ %d*%d ▶", m_MapSize, m_MapSize);
				}
			}
			else if (shipSellect == 1 || shipSellect == 2 || shipSellect == 3 || shipSellect == 4)
			{
				if (m_NumShip[shipSellect - 1] > 0)
				{
					m_NumShip[shipSellect - 1] -= 1;
					GotoXY(gotoX + 40, currentPositionY);
					printf_s("◀  %d  ▶", m_NumShip[shipSellect - 1]);
				}
			}
		}
		else if (keyinput == KEY_RIGHT)
		{
			if (shipSellect == 0)
			{
				if (m_MapSize < 9)
				{
					m_MapSize += 1;
					GotoXY(gotoX + 40, currentPositionY);
					printf_s("◀ %d*%d ▶", m_MapSize, m_MapSize);
				}
			}
			if (shipSellect == 1 || shipSellect == 2 || shipSellect == 3 || shipSellect == 4)
			{
				if (m_NumShip[shipSellect - 1] < 3)
				{
					m_NumShip[shipSellect - 1] += 1;
					GotoXY(gotoX + 40, currentPositionY);
					printf_s("◀  %d  ▶", m_NumShip[shipSellect - 1]);
				}
			}
		}
		else if (keyinput == ENTER)
		{
			if (okToStart == true && ValidMapSize() == true && shipSellect == 5)
			{
				break;
			}
		}
	}
}

void GameRender::RenderShipSettingPage(Map& map)
{
	SetColor(WHITE, BLACK);
	int widthForMap = (map.GetMaxSizeofMap() + 4) * 4;
	int heightForMap = (map.GetMaxSizeofMap() + 4) * 2 + 10;
	int menuSpace = 30;//추가 공간 30
	SetConsoleSize(widthForMap + menuSpace, heightForMap); 
	system("cls");
	SetColor(BLACK, WHITE);
	printf_s("                                                             \n");
	printf_s("   ■■■ ■■■ ■■■■ ■■■■ ■■■ ■    ■   ■■■  \n");
	printf_s("  ■      ■        ■       ■      ■   ■■  ■  ■    ■ \n");
	printf_s("   ■■   ■■■    ■       ■      ■   ■ ■ ■ ■        \n");
	printf_s("       ■ ■        ■       ■      ■   ■  ■■  ■  ■■ \n");
	printf_s("  ■■■  ■■■    ■       ■    ■■■ ■    ■   ■■ ■ \n");
	printf_s("                                                             \n");
	for (int j = 0; j < 7; j++)
	{
		GotoXY(61, j);
		for (int i = 0; i < widthForMap + menuSpace - 62; i++)
		{
			printf_s(" ");
		}
	}

	SetColor(WHITE, BLACK);
	RenderMap(map, 4, 9);

	int gotoX = widthForMap;
	int gotoY = 7;

	GotoXY(gotoX + 6, gotoY + 5);
	printf_s("Manual Set");
	GotoXY(gotoX + 6, gotoY + 8);
	printf_s("Random Set");
	GotoXY(gotoX + 6, gotoY + 11);
	printf_s("Reset");
	SetColor(BLACK, WHITE);
	GotoXY(gotoX + 2, gotoY + 16);
	printf_s("                  \n");
	GotoXY(gotoX + 2, gotoY + 17);
	printf_s("    Start Game    \n");
	GotoXY(gotoX + 2, gotoY + 18);
	printf_s("                  ");
	
	GotoXY(6, heightForMap - 5);
	RenderRemain();

	ShipSettingMenu(map);
}

void GameRender::ShipSettingMenu(Map& map)
{
	int widthForMap = (map.GetMaxSizeofMap() + 4) * 4;
	int heightForMap = (map.GetMaxSizeofMap() + 4) * 2 + 10;
	int menuSpace = 30;//추가 공간 30
	int gotoX = widthForMap;
	int gotoY = 7;
	int menuSellect = 0;
	int currentPositionY = gotoY + 5;
	GotoXY(gotoX, currentPositionY);
	SetColor(WHITE, BLACK);
	printf_s("▶");
	GotoXY(widthForMap + menuSpace - 1, heightForMap - 1);
	while (true)
	{
		GotoXY(widthForMap + menuSpace - 1, heightForMap - 1);
		int keyinput;
		keyinput = _getch();
		if (keyinput == -32)
		{
			keyinput = _getch();
		}
		if (keyinput == KEY_DOWN)
		{
			if (menuSellect == 0 || menuSellect == 1)
			{
				GotoXY(gotoX, currentPositionY);
				printf_s("  ");
				currentPositionY += 3;
				menuSellect += 1;
				GotoXY(gotoX, currentPositionY);
				printf_s("▶");
			}
		}
		else if (keyinput == KEY_UP)
		{
			if (menuSellect == 1 || menuSellect == 2)
			{
				GotoXY(gotoX, currentPositionY);
				printf_s("  ");
				currentPositionY -= 3;
				menuSellect -= 1;
				GotoXY(gotoX, currentPositionY);
				printf_s("▶");
			}
		}
		else if (keyinput == ENTER)
		{
			if (menuSellect == 0)
			{
				//SetUpShipsOnMap();
			}
			else if (menuSellect == 1)
			{}
			else //reset
			{
				//RenderShipSettingPage(map);
				//추가한 좌표벡터 비우기
			}
			//Pass the value in playerSellect to GameSetting class
			break;
		}
	}
}



//default x=9, y=11

void GameRender::RenderShipOnMap(ShipType shiptype, int gotoX, int gotoY, Direction direction)
{
	for (int i = 0; i < GetMaxHP(shiptype); i++)
	{
		if (gotoX < 9 || gotoX > 4 * (m_MapSize - 1) + 9 || gotoY < 11 || gotoY > 2 * (m_MapSize - 1) + 11)
			return;
		GotoXY(gotoX, gotoY);
		SetColor(GetForeColor(shiptype), GetBackColor(shiptype));
		printf_s("%s", GetShipChar(shiptype).c_str());
		switch (direction)
		{
		case UP:
			gotoY -= 2;
			break;
		case DOWN:
			gotoY += 2;
			break;
		case LEFT:
			gotoX -= 4;
			break;
		case RIGHT:
			gotoX += 4;
			break;
		}
	}
}
void GameRender::RenderSpaceOnMap(ShipType shiptype, int gotoX, int gotoY, Direction direction)
{
	for (int i = 0; i < GetMaxHP(shiptype); i++)
	{
		if (gotoX < 9 || gotoX > 4 * (m_MapSize - 1) + 9 || gotoY < 11 || gotoY > 2 * (m_MapSize - 1) + 11)
			return;
		GotoXY(gotoX, gotoY);
		SetColor(WHITE, BLACK);
		printf_s("  ");
		switch (direction)
		{
		case UP:
			gotoY -= 2;
			break;
		case DOWN:
			gotoY += 2;
			break;
		case LEFT:
			gotoX -= 4;
			break;
		case RIGHT:
			gotoX += 4;
			break;
		}
	}
}

void GameRender::RenderMap(Map& map, int gotoX, int gotoY)
{
	int maxSizeOfMap = map.GetMaxSizeofMap();
	GotoXY(0, gotoY);
	for (int j = 0; j < maxSizeOfMap * 2 + 2; j++)
	{
		for (int k = 0; k < gotoX; k++)
		{
			printf_s(" ");
		}
		for (int i = 0; i < maxSizeOfMap + 2; i++)
		{
			if (j == 0)
			{
				if (i == 0)
					printf_s("   ");
				else if (i == maxSizeOfMap + 1)
					printf_s("");
				else
					printf_s("   %c", '1' + i - 1);
			}
			else if (j == 1)
			{
				if (i == 0)
					printf_s("   ");
				else if (i == 1)
					printf_s("┌");
				else if (i == maxSizeOfMap + 1)
					printf_s("─┐");
				else if (i >= 2)
					printf_s("─┬");
			}
			else if (j == maxSizeOfMap * 2 + 1)
			{
				if (i == 0)
					printf_s("   ");
				else if (i == 1)
					printf_s("└");
				else if (i == maxSizeOfMap + 1)
					printf_s("─┘");
				else if (i >= 2)
					printf_s("─┴");
			}
			else if (j % 2 == 0)
			{
				if (i == 0)
					printf_s(" %c ", 'A' + (j / 2) - 1);
				else
					printf_s("│  ");
			}
			else // j % 2 == 1
			{
				if (i == 0)
					printf_s("   ");
				else if (i == 1)
					printf_s("├");
				else if (i == maxSizeOfMap + 1)
					printf_s("─┤");
				else if (i >= 2)
					printf_s("─┼");
			}
		}
		printf_s("\n");
	}
}

void GameRender::RenderRemain() //H.ShipType
{
	SetColor(BLACK, WHITE);
	printf_s(" Remain ");
	SetColor(WHITE, BLACK);
	printf_s(" ");
	for (int i = 0; i < SHIPTYPECOUNT; i++)
	{
		for (int j = 0; j < m_NumShip[i]; j++)
		{
			SetColor(GetForeColor((ShipType)i), GetBackColor((ShipType)i));
			printf_s("%s", GetShipChar((ShipType)i).c_str());
			SetColor(WHITE, BLACK);
			printf_s(" ");
		}
	}
}

//MAKE VALUE FUNCTION
void GameRender::SetUpShipOnMap(ShipType shiptype, Map& map)
{
	int currentX = 9;
	int currentY = 11;
	Direction direction = DOWN;
	GotoXY(currentX, currentY);
	RenderShipOnMap(shiptype, currentX, currentY, direction);
	while (true)
	{
		GotoXY(currentX, currentY);
		int keyinput;
		keyinput = _getch();
		if (keyinput == -32)
		{
			keyinput = _getch();
		}
		if (keyinput == KEY_DOWN)
		{
			if (currentY < 2 * (m_MapSize - 1) + 11)
			{
				RenderSpaceOnMap(shiptype, currentX, currentY, direction);
				currentY += 2;
				RenderShipOnMap(shiptype, currentX, currentY, direction);
			}
		}
		else if (keyinput == KEY_UP)
		{
			if (currentY > 11)
			{
				RenderSpaceOnMap(shiptype, currentX, currentY, direction);
				currentY -= 2;
				RenderShipOnMap(shiptype, currentX, currentY, direction);
			}
		}
		else if (keyinput == KEY_LEFT)
		{
			if (currentX > 9)
			{
				RenderSpaceOnMap(shiptype, currentX, currentY, direction);
				currentX -= 4;
				RenderShipOnMap(shiptype, currentX, currentY, direction);
			}
		}
		else if (keyinput == KEY_RIGHT)
		{
			if (currentX < 4 * (m_MapSize - 1) + 9)
			{
				RenderSpaceOnMap(shiptype, currentX, currentY, direction);
				currentX += 4;
				RenderShipOnMap(shiptype, currentX, currentY, direction);
			}
		}
		else if (keyinput == SPACE)
		{
			RenderSpaceOnMap(shiptype, currentX, currentY, direction);
			direction = (Direction)(((int)direction + 1) % 4);
			RenderShipOnMap(shiptype, currentX, currentY, direction);
		}
		else if (keyinput == ENTER)
		{
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
	std::stringstream makeThemOne;
	std::string str1 = "mode con:cols=";
	std::string str2 = " lines=";
	makeThemOne << str1 << width << str2 << height;
	std::string sumStr = makeThemOne.str();
	const char* resultStr = sumStr.c_str();
	system(resultStr);
}

bool GameRender::ValidMapSize()
{
	int sumShipTile = m_NumShip[0] * 5 + m_NumShip[1] * 4 + m_NumShip[2] * 3 + m_NumShip[3] * 2;
	if (sumShipTile < m_MapSize * m_MapSize - 10)
		return true;
	else
		return false;
}


