#include "stdafx.h"
#include "GameManager.h"
#include "HeaderSet.h"
#include <conio.h>
#include "Map.h"

GameManager::GameManager()
{
}


GameManager::~GameManager()
{
}

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


void GameManager::PlayerSettingPage()
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
//menu sellect 분리하기

void GameManager::GameSettingPage()
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
//menu sellect 분리하기

void GameManager::ShipSettingPage(Map& map)
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
		for (int i = 0; i < widthForMap + menuSpace - 61; i++)
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
	SetColor(BLACK, WHITE);
	GotoXY(gotoX + 2, gotoY + 12);
	printf_s("                  \n");
	GotoXY(gotoX + 2, gotoY + 13);
	printf_s("    Start Game    \n");
	GotoXY(gotoX + 2, gotoY + 14);
	printf_s("                  \n");
	GotoXY(gotoX + 2, gotoY + 17);
	printf_s("                  \n");
	GotoXY(gotoX + 2, gotoY + 18);
	printf_s("       Reset      \n");
	GotoXY(gotoX + 2, gotoY + 19);
	printf_s("                  ");
	
	GotoXY(6, heightForMap - 5);
	RenderRemain();

	if (ShipSettingMenu(map) == 1)
	{
		//ManualSet
	}
	else
	{
		//RandomSet
	}
}

int GameManager::ShipSettingMenu(Map& map)
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
			if (menuSellect == 0)
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
			if (menuSellect == 1)
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
			GotoXY(gotoX, currentPositionY);
			SetColor(BLACK, BLACK);
			printf_s("  ");
			if (menuSellect == 0)
			{
				return 1;
			}
			else if (menuSellect == 1)
			{
				return 2;
			}
			break;
		}
	}
}


void GameManager::GamePlayPage(Map& EnemyMap, Map& MyMap)
{
	SetColor(WHITE, BLACK);
	int widthForMap = (MyMap.GetMaxSizeofMap() + 3) * 4;
	int heightForMap = (MyMap.GetMaxSizeofMap() + 4) * 2 + 9;
	int menuSpace = 25;//추가 공간 30
	SetConsoleSize((widthForMap * 2) + menuSpace, heightForMap);
	system("cls");
	SetColor(BLACK, WHITE);
	printf_s("                                                                          \n");
	printf_s("    ■■■     ■    ■■  ■■ ■■■■   ■■■  ■        ■  ■    ■ \n");
	printf_s("   ■    ■   ■■   ■ ■■ ■ ■         ■   ■ ■       ■■  ■  ■  \n");
	printf_s("  ■         ■  ■  ■  ■  ■ ■■■     ■■■  ■      ■  ■  ■■   \n");
	printf_s("   ■  ■■ ■■■■ ■      ■ ■         ■      ■     ■■■■  ■    \n");
	printf_s("    ■■ ■ ■    ■ ■      ■ ■■■■   ■      ■■■ ■    ■  ■    \n");
	printf_s("                                                                          \n");
	for (int j = 0; j < 7; j++)
	{
		GotoXY(74, j);
		for (int i = 0; i < (widthForMap * 2) + menuSpace - 74; i++)
		{
			printf_s(" ");
		}
	}

	SetColor(WHITE, BLACK);

	RenderMap(MyMap, widthForMap + menuSpace, 9);
	GotoXY(widthForMap + menuSpace + widthForMap / 2 - 6, 8 + (MyMap.GetMaxSizeofMap() + 2) * 2);
	printf_s("< My Map >");

	RenderMap(EnemyMap, 4, 9);
	GotoXY(widthForMap / 2 - 6, 8 + (MyMap.GetMaxSizeofMap() + 2) * 2);
	printf_s("< Enemy Map >");

	int gotoX = widthForMap + 2;
	int gotoY = 6;
	
	GotoXY(gotoX, gotoY + 4);
	printf_s("┌─  Result  ─┐");
	GotoXY(gotoX, gotoY + 5);
	printf_s("│              │");
	GotoXY(gotoX, gotoY + 6);
	printf_s("│              │");
	GotoXY(gotoX, gotoY + 7);
	printf_s("│              │");
	GotoXY(gotoX, gotoY + 8);
	printf_s("└───────┘");

	GotoXY(gotoX, gotoY + 10);
	printf_s("■ SMITH  GAMES ■");
	
	GotoXY(gotoX, gotoY + 12);
	printf_s("┌── turn ──┐");
	GotoXY(gotoX, gotoY + 13);
	printf_s("│              │");
	GotoXY(gotoX, gotoY + 14);
	printf_s("│              │");
	GotoXY(gotoX, gotoY + 15);
	printf_s("│              │");
	GotoXY(gotoX, gotoY + 16);
	printf_s("└───────┘");
}

//default x=9, y=11

Coordinate GameManager::AttakInterface()
{
	int startPointX = 9;
	int startPointY = 11;
	int currentX = startPointX;
	int currentY = startPointY;
	Coordinate attackCoordinate;
	SetColor(WHITE, WHITE);
	GotoXY(currentX, currentY);
	printf_s("  ");
	while (true)
	{
		char shipCoordX = (currentX - startPointX) / 4 + '0';
		char shipCoordY = (currentY - startPointY) / 2 + '0';
		GotoXY(currentX, currentY);
		int keyinput;
		keyinput = _getch();
		if (keyinput == -32)
		{
			keyinput = _getch();
		}
		if (keyinput == KEY_DOWN)
		{
			if (currentY < 2 * (m_MapSize - 1) + startPointY)
			{
				SetColor(BLACK, BLACK);
				GotoXY(currentX, currentY);
				printf_s("  ");
				currentY += 2;
				SetColor(WHITE, WHITE);
				GotoXY(currentX, currentY);
				printf_s("  ");
			}
		}
		else if (keyinput == KEY_UP)
		{
			if (currentY > startPointY)
			{
				SetColor(BLACK, BLACK);
				GotoXY(currentX, currentY);
				printf_s("  ");
				currentY -= 2;
				SetColor(WHITE, WHITE);
				GotoXY(currentX, currentY);
				printf_s("  ");
			}
		}
		else if (keyinput == KEY_LEFT)
		{
			if (currentX > startPointX)
			{
				SetColor(BLACK, BLACK);
				GotoXY(currentX, currentY);
				printf_s("  ");
				currentX -= 4;
				SetColor(WHITE, WHITE);
				GotoXY(currentX, currentY);
				printf_s("  ");
			}
		}
		else if (keyinput == KEY_RIGHT)
		{
			if (currentX < 4 * (m_MapSize - 1) + startPointX)
			{
				SetColor(BLACK, BLACK);
				GotoXY(currentX, currentY);
				printf_s("  ");
				currentX += 4;
				SetColor(WHITE, WHITE);
				GotoXY(currentX, currentY);
				printf_s("  ");
			}
		}
		else if (keyinput == ENTER)
		{
			attackCoordinate.m_X = shipCoordX;
			attackCoordinate.m_Y = shipCoordY;
			break;
		}
	}
	return attackCoordinate;
}


void GameManager::RenderShipOnMap(ShipType shiptype, int gotoX, int gotoY, Direction direction)
{
	//default x=9, y=11
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

void GameManager::RenderSpaceOnMap(ShipType shiptype, int gotoX, int gotoY, Direction direction)
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

void GameManager::RenderMap(Map& map, int gotoX, int gotoY)
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

void GameManager::RenderRemain() //H.ShipType
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
void GameManager::SetUpShipOnMap(ShipType shiptype, Map& map)
{
	int startPointX = 9;
	int startPointY = 11;
	int currentX = startPointX;
	int currentY = startPointY;
	Direction direction = DOWN;
	GotoXY(currentX, currentY);
	RenderShipOnMap(shiptype, currentX, currentY, direction);
	while (true)
	{
		char shipCoordX = (currentX - startPointX) / 4 + '0';
		char shipCoordY = (currentY - startPointY) / 2 + '0';
		GotoXY(currentX, currentY);
		int keyinput;
		keyinput = _getch();
		if (keyinput == -32)
		{
			keyinput = _getch();
		}
		if (keyinput == KEY_DOWN)
		{
			if (currentY < 2 * (m_MapSize - 1) + startPointY)
			{
					RenderSpaceOnMap(shiptype, currentX, currentY, direction);
					currentY += 2;
					RenderShipOnMap(shiptype, currentX, currentY, direction);
			}
		}
		else if (keyinput == KEY_UP)
		{
			if (currentY > startPointY)
			{
				RenderSpaceOnMap(shiptype, currentX, currentY, direction);
				currentY -= 2;
				RenderShipOnMap(shiptype, currentX, currentY, direction);
			}
		}
		else if (keyinput == KEY_LEFT)
		{
			if (currentX > startPointX)
			{
				RenderSpaceOnMap(shiptype, currentX, currentY, direction);
				currentX -= 4;
				RenderShipOnMap(shiptype, currentX, currentY, direction);
			}
		}
		else if (keyinput == KEY_RIGHT)
		{
			if (currentX < 4 * (m_MapSize - 1) + startPointX)
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
			Coordinate startCoordinate;
			startCoordinate.m_X = shipCoordX;
			startCoordinate.m_Y = shipCoordY;
			m_startCoordinates.push_back(startCoordinate);
			m_Directions.push_back(direction);
			m_NumShip[(int)shiptype]--;
			break;
		}
	}
}

void GameManager::PrintResult(HitResult hitResult)
{
	SetColor(WHITE, BLACK);
	switch (hitResult)
	{
	case NOTHING:
		GotoXY((m_MapSize + 3) * 4 + 4, 12);
		printf_s(" Result Error ");
		break;
	case HIT:
		GotoXY((m_MapSize + 3) * 4 + 4, 12);
		printf_s("     HIT!     ");
		break;
	case MISS:
		GotoXY((m_MapSize + 3) * 4 + 4, 12);
		printf_s("     MISS     ");
		break;
	case DESTROY_AIRCRAFT:
		GotoXY((m_MapSize + 3) * 4 + 4, 12);
		printf_s("   Aircraft   ");
		GotoXY((m_MapSize + 3) * 4 + 4, 13);
		printf_s("  Destroyed!  ");
		break;
	case DESTROY_BATTLESHIP:
		GotoXY((m_MapSize + 3) * 4 + 4, 12);
		printf_s("  Battleship  ");
		GotoXY((m_MapSize + 3) * 4 + 4, 13);
		printf_s("  Destroyed!  ");
		break;
	case DESTROY_CRUISER:
		GotoXY((m_MapSize + 3) * 4 + 4, 12);
		printf_s("   Cruiser    ");
		GotoXY((m_MapSize + 3) * 4 + 4, 13);
		printf_s("  Destroyed!  ");
		break;
	case DESTROY_DESTROYER:
		GotoXY((m_MapSize + 3) * 4 + 4, 12);
		printf_s("  Destroyer   ");
		GotoXY((m_MapSize + 3) * 4 + 4, 13);
		printf_s("  Destroyed!  ");
		break;
	default:
		break;
	}
	getchar();
}

void GameManager::PrintTurn()
{
	SetColor(WHITE, BLACK);
	m_Turn = 4;
	GotoXY((m_MapSize + 3) * 4 + 4, 20);
	printf_s("      %2d      ", m_Turn);
}


//SET CONSOLE FUNCTIONS
void GameManager::GotoXY(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void GameManager::SetColor(int fcolor, int bcolor)
{
	fcolor &= 0xf;
	bcolor &= 0xf;
	SetConsoleTextAttribute(hConsole, (bcolor << 4) | fcolor);
}

void GameManager::SetConsoleSize(int width, int height)
{
	std::stringstream makeThemOne;
	std::string str1 = "mode con:cols=";
	std::string str2 = " lines=";
	makeThemOne << str1 << width << str2 << height;
	std::string sumStr = makeThemOne.str();
	const char* resultStr = sumStr.c_str();
	system(resultStr);
}

bool GameManager::ValidMapSize()
{
	int sumShipTile = m_NumShip[0] * 5 + m_NumShip[1] * 4 + m_NumShip[2] * 3 + m_NumShip[3] * 2;
	if (sumShipTile < m_MapSize * m_MapSize - 10)
		return true;
	else
		return false;
}



//TO RENDER CLASS


//RENDERINT SCREEN FUNCTIONS
void GameManager::RenderTitle()
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

void GameManager::RenderWin()
{
	system("cls");
	SetColor(BLACK, WHITE);
	SetConsoleSize(62, 7);
	printf_s("                                                             \n");
	printf_s("   ■    ■  ■■   ■    ■    ■      ■ ■■■ ■    ■   \n");
	printf_s("    ■  ■ ■    ■ ■    ■    ■      ■   ■   ■■  ■   \n");
	printf_s("     ■■  ■    ■ ■    ■    ■  ■  ■   ■   ■ ■ ■   \n");
	printf_s("      ■   ■    ■ ■    ■     ■ ■ ■    ■   ■  ■■   \n");
	printf_s("      ■     ■■    ■■■       ■  ■   ■■■ ■    ■   \n");
	printf_s("                                                             ");
}

void GameManager::RenderLose()
{
	system("cls");
	SetColor(BLACK, WHITE);
	SetConsoleSize(67, 7);
	printf_s("                                                                  \n");
	printf_s("   ■    ■  ■■   ■    ■    ■       ■■    ■■■  ■■■   \n");
	printf_s("    ■  ■ ■    ■ ■    ■    ■     ■    ■ ■       ■       \n");
	printf_s("     ■■  ■    ■ ■    ■    ■     ■    ■  ■■■  ■■■   \n");
	printf_s("      ■   ■    ■ ■    ■    ■     ■    ■       ■ ■       \n");
	printf_s("      ■     ■■    ■■■     ■■■   ■■    ■■■  ■■■   \n");
	printf_s("                                                                  ");

}
