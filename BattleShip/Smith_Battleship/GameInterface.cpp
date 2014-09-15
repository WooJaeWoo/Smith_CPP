#include "stdafx.h"
#include "GameInterface.h"
#include "GameRenderer.h"
#include "Map.h"

GameInterface::GameInterface()
{
	m_GameRenderer = new GameRenderer();
	m_GameType = PVA;
	m_MapSize = 8;
	m_NumShip.clear();
	m_ManualOrRandom = false;
	m_LastMenu = -1;
}

GameInterface::~GameInterface()
{
	delete m_GameRenderer;
}

void GameInterface::InitializeInterface()
{
	m_GameType = PVA;
	m_MapSize = 8;
	m_NumShip.clear();
	m_NumShip.push_back(1);
	m_NumShip.push_back(1);
	m_NumShip.push_back(1);
	m_NumShip.push_back(2);
	m_ManualOrRandom = false;
	m_LastMenu = -1;
}
void GameInterface::ResetInterface()
{
	m_ManualOrRandom = false;
	m_LastMenu = -1;
}

void GameInterface::DefaultInterface()
{
	m_GameType = AVN;
	m_MapSize = 8;
	m_NumShip.clear();
	m_NumShip.push_back(1);
	m_NumShip.push_back(1);
	m_NumShip.push_back(1);
	m_NumShip.push_back(2);
}

void GameInterface::AttachInterface(GameStatus gameStatus)
{
	int gotoX;
	int gotoY;
	int currentY;
	int menuSelector = 0;
	switch (gameStatus)
	{
	case TITLE:
		gotoX = 0;
		gotoY = 10;
		while (!_kbhit())
		{
			Sleep(600);
			SetCursorPosition(gotoX, gotoY);
			printf_s("\t\t\t     PRESS ENTER KEY TO START      \t\t\t");
			Sleep(1000);
			SetCursorPosition(gotoX, gotoY);
			printf_s("                                                                            ");
		}
		getchar();
		break;
	case SELECT_PLAYER:
		gotoX = 22;
		gotoY = 9;
		currentY = gotoY + 6;
		SetColor(BLACK, WHITE);
		SetCursorPosition(gotoX, gotoY);
		printf_s("                  \n");
		SetCursorPosition(gotoX, gotoY + 1);
		printf_s("   PLAYER SELECT  \n");
		SetCursorPosition(gotoX, gotoY + 2);
		printf_s("                  ");
		SetColor(WHITE, BLACK);
		SetCursorPosition(gotoX + 7, gotoY + 6);
		printf_s("VS Friend");
		SetCursorPosition(gotoX + 7, gotoY + 9);
		printf_s("VS AI");
		SetCursorPosition(gotoX + 7, gotoY + 12);
		printf_s("VS Network");
		SetCursorPosition(gotoX - 1, currentY);
		printf_s("¢º");
		menuSelector = MenuSelect(3, gotoX, gotoY, currentY, gameStatus);
		if (menuSelector == 0)
		{
			m_GameType = PVP;
		}
		else if (menuSelector == 1)
		{
			m_GameType = PVA;
		}
		else if (menuSelector == 2)
		{
			m_GameType = AVN;
		}
		break;
	case SELECT_MAP_SHIP:
		gotoX = 4;
		gotoY = 9;
		currentY = gotoY + 5;
		SetColor(BLACK, WHITE);
		SetCursorPosition(gotoX + 18, gotoY);
		printf_s("                  \n");
		SetCursorPosition(gotoX + 18, gotoY + 1);
		printf_s("    SHIP SELECT   \n");
		SetCursorPosition(gotoX + 18, gotoY + 2);
		printf_s("                  ");
		SetColor(WHITE, BLACK);
		SetCursorPosition(gotoX + 6, gotoY + 5);
		printf_s("Map size");
		SetCursorPosition(gotoX + 6, gotoY + 8);
		printf_s("Aircraft Carrier");
		SetCursorPosition(gotoX + 6, gotoY + 11);
		printf_s("Battleship");
		SetCursorPosition(gotoX + 6, gotoY + 14);
		printf_s("Cruiser");
		SetCursorPosition(gotoX + 6, gotoY + 17);
		printf_s("Destroyer");
		SetColor(BLACK, WHITE);
		SetCursorPosition(gotoX + 18, gotoY + 20);
		printf_s("                   \n");
		SetCursorPosition(gotoX + 18, gotoY + 21);
		printf_s("      N E X T      \n");
		SetCursorPosition(gotoX + 18, gotoY + 22);
		printf_s("                   ");
		SetColor(WHITE, BLACK);
		SetCursorPosition(gotoX + 40, gotoY + 5);
		printf_s("¢¸ %d*%d ¢º", m_MapSize, m_MapSize);
		SetCursorPosition(gotoX + 40, gotoY + 8);
		printf_s("¢¸  %d  ¢º", m_NumShip[0]);
		SetCursorPosition(gotoX + 40, gotoY + 11);
		printf_s("¢¸  %d  ¢º", m_NumShip[1]);
		SetCursorPosition(gotoX + 40, gotoY + 14);
		printf_s("¢¸  %d  ¢º", m_NumShip[2]);
		SetCursorPosition(gotoX + 40, gotoY + 17);
		printf_s("¢¸  %d  ¢º", m_NumShip[3]);
		SetCursorPosition(gotoX, currentY);
		printf_s("¢º");
		menuSelector = MenuSelect(6, gotoX, gotoY, currentY, gameStatus);
		break;
	case SET_SHIP:
		gotoX = (m_MapSize + 3) * 4 + 4;
		gotoY = 7;
		currentY = gotoY + 5;
		SetCursorPosition(gotoX + 6, gotoY + 5);
		printf_s("Manual Set");
		SetCursorPosition(gotoX + 6, gotoY + 8);
		printf_s("Random Set");
		SetCursorPosition(gotoX, currentY);
		printf_s("¢º");
		SetColor(BLACK, WHITE);
		SetCursorPosition(gotoX + 2, gotoY + 12);
		printf_s("                  \n");
		SetCursorPosition(gotoX + 2, gotoY + 13);
		printf_s("    Start Game    \n");
		SetCursorPosition(gotoX + 2, gotoY + 14);
		printf_s("                  \n");
		SetCursorPosition(gotoX + 2, gotoY + 17);
		printf_s("                  \n");
		SetCursorPosition(gotoX + 2, gotoY + 18);
		printf_s("       Reset      \n");
		SetCursorPosition(gotoX + 2, gotoY + 19);
		printf_s("                  ");
		SetColor(WHITE, BLACK);
		menuSelector = MenuSelect(2, gotoX, gotoY, currentY, gameStatus);
		if (menuSelector == 0)
		{
			m_ManualOrRandom = true;
		}
		else if (menuSelector == 1)
		{
			m_ManualOrRandom = false;
		}
		SetColor(WHITE, BLACK);
		break;
	case GAMEPLAY:
		break;
	case WIN:
		gotoX = 3;
		gotoY = 13;
		currentY = 0;
		SetColor(BLACK, GREEN);
		SetCursorPosition(gotoX, gotoY);
		printf_s("                \n");
		SetCursorPosition(gotoX, gotoY + 1);
		printf_s("    To Title    \n");
		SetCursorPosition(gotoX, gotoY + 2);
		printf_s("  (New Setting) \n");
		SetCursorPosition(gotoX, gotoY + 3);
		printf_s("                ");
		SetColor(BLACK, WHITE);
		SetCursorPosition(gotoX + 20, gotoY);
		printf_s("                \n");
		SetCursorPosition(gotoX + 20, gotoY + 1);
		printf_s("   Play Again   \n");
		SetCursorPosition(gotoX + 20, gotoY + 2);
		printf_s(" (Same Setting) \n");
		SetCursorPosition(gotoX + 20, gotoY + 3);
		printf_s("                ");
		SetCursorPosition(gotoX + 40, gotoY);
		printf_s("                \n");
		SetCursorPosition(gotoX + 40, gotoY + 1);
		printf_s("      Quit      \n");
		SetCursorPosition(gotoX + 40, gotoY + 2);
		printf_s("      Game      \n");
		SetCursorPosition(gotoX + 40, gotoY + 3);
		printf_s("                ");
		SetColor(WHITE, BLACK);
		m_LastMenu = MenuSelect(3, gotoX, gotoY, currentY, gameStatus);
		break;
	case LOSE:
		gotoX = 6;
		gotoY = 13;
		currentY = 0;
		SetColor(BLACK, GREEN);
		SetCursorPosition(gotoX, gotoY);
		printf_s("                \n");
		SetCursorPosition(gotoX, gotoY + 1);
		printf_s("    To Title    \n");
		SetCursorPosition(gotoX, gotoY + 2);
		printf_s("  (New Setting) \n");
		SetCursorPosition(gotoX, gotoY + 3);
		printf_s("                ");
		SetColor(BLACK, WHITE);
		SetCursorPosition(gotoX + 20, gotoY);
		printf_s("                \n");
		SetCursorPosition(gotoX + 20, gotoY + 1);
		printf_s("   Play Again   \n");
		SetCursorPosition(gotoX + 20, gotoY + 2);
		printf_s(" (Same Setting) \n");
		SetCursorPosition(gotoX + 20, gotoY + 3);
		printf_s("                ");
		SetCursorPosition(gotoX + 40, gotoY);
		printf_s("                \n");
		SetCursorPosition(gotoX + 40, gotoY + 1);
		printf_s("      Quit      \n");
		SetCursorPosition(gotoX + 40, gotoY + 2);
		printf_s("      Game      \n");
		SetCursorPosition(gotoX + 40, gotoY + 3);
		printf_s("                ");
		SetColor(WHITE, BLACK);
		m_LastMenu = MenuSelect(3, gotoX, gotoY, currentY, gameStatus);
		break;
	}
}

int GameInterface::MenuSelect(int menuSize, int gotoX, int gotoY, int currentY, GameStatus gameStatus)
{
	int menuSelector = 0;
	bool okToStart = false;
	int sumShips;
	while (true)
	{
		int keyinput;
		keyinput = _getch();
		if (keyinput == -32)
		{
			keyinput = _getch();
		}
		if (keyinput == KEY_DOWN)
		{
			if (gameStatus == SELECT_PLAYER || gameStatus == SET_SHIP)
			{
				if (menuSelector >= 0 && menuSelector < menuSize - 1)
				{
					SetCursorPosition(gotoX, currentY);
					printf_s("  ");
					currentY += 3;
					menuSelector += 1;
					SetCursorPosition(gotoX, currentY);
					printf_s("¢º");
				}
			}
			else if (gameStatus == SELECT_MAP_SHIP)
			{
				if (menuSelector >= 0 && menuSelector < menuSize - 2)
				{
					SetCursorPosition(gotoX, currentY);
					printf_s("  ");
					currentY += 3;
					menuSelector += 1;
					SetCursorPosition(gotoX, currentY);
					printf_s("¢º");
				}
				else if (menuSelector == menuSize - 2)
				{
					sumShips = GetSumShip();
					SetCursorPosition(gotoX, currentY);
					printf_s("  ");
					currentY += 3;
					menuSelector += 1;
					if (sumShips == 0)
					{
						okToStart = false;
						SetColor(BLACK, DARK_RED);
						SetCursorPosition(gotoX + 18, gotoY + 20);
						printf_s("                   \n");
						SetCursorPosition(gotoX + 18, gotoY + 21);
						printf_s("      No Ship      \n");
						SetCursorPosition(gotoX + 18, gotoY + 22);
						printf_s("                   ");
					}
					else if (CheckEnoughSize() == false)
					{
						okToStart = false;
						SetColor(BLACK, DARK_RED);
						SetCursorPosition(gotoX + 18, gotoY + 20);
						printf_s("                   \n");
						SetCursorPosition(gotoX + 18, gotoY + 21);
						printf_s("   Too Many Ships  \n");
						SetCursorPosition(gotoX + 18, gotoY + 22);
						printf_s("                   ");
					}
					else
					{
						okToStart = true;
						SetColor(BLACK, GREEN);
						SetCursorPosition(gotoX + 18, gotoY + 20);
						printf_s("                   \n");
						SetCursorPosition(gotoX + 18, gotoY + 21);
						printf_s("      N E X T      \n");
						SetCursorPosition(gotoX + 18, gotoY + 22);
						printf_s("                   ");
					}
				}
			}
		}
		else if (keyinput == KEY_UP)
		{
			if (gameStatus == SELECT_PLAYER || gameStatus == SET_SHIP)
			{
				if (menuSelector >= 1 && menuSelector < menuSize)
				{
					SetCursorPosition(gotoX, currentY);
					printf_s("  ");
					currentY -= 3;
					menuSelector -= 1;
					SetCursorPosition(gotoX, currentY);
					printf_s("¢º");
				}
			}
			else if (gameStatus == SELECT_MAP_SHIP)
			{
				if (menuSelector >= 1 && menuSelector < menuSize - 1)
				{
					SetCursorPosition(gotoX, currentY);
					printf_s("  ");
					currentY -= 3;
					menuSelector -= 1;
					SetCursorPosition(gotoX, currentY);
					printf_s("¢º");
				}
				else if (menuSelector == menuSize - 1)
				{
					currentY -= 3;
					menuSelector -= 1;
					SetColor(BLACK, WHITE);
					SetCursorPosition(gotoX + 18, gotoY + 20);
					printf_s("                   \n");
					SetCursorPosition(gotoX + 18, gotoY + 21);
					printf_s("      N E X T      \n");
					SetCursorPosition(gotoX + 18, gotoY + 22);
					printf_s("                   ");
					SetColor(WHITE, BLACK);
					SetCursorPosition(gotoX, currentY);
					printf_s("¢º");
				}
			}
		}
		else if (keyinput == KEY_LEFT)
		{
			if (gameStatus == SELECT_MAP_SHIP)
			{
				if (menuSelector == 0)
				{
					if (m_MapSize > 5)
					{
						m_MapSize -= 1;
						SetCursorPosition(gotoX + 40, currentY);
						printf_s("¢¸ %d*%d ¢º", m_MapSize, m_MapSize);
					}
				}
				else if (menuSelector >= 1 && menuSelector <= menuSize - 2)
				{
					if (m_NumShip[menuSelector - 1] > 0)
					{
						m_NumShip[menuSelector - 1] -= 1;
						SetCursorPosition(gotoX + 40, currentY);
						printf_s("¢¸  %d  ¢º", m_NumShip[menuSelector - 1]);
					}
				}
			}
			if (gameStatus == WIN || gameStatus == LOSE)
			{
				if (menuSelector == 1)
				{
					menuSelector--;
					SetColor(BLACK, GREEN);
					SetCursorPosition(gotoX, gotoY);
					printf_s("                \n");
					SetCursorPosition(gotoX, gotoY + 1);
					printf_s("    To Title    \n");
					SetCursorPosition(gotoX, gotoY + 2);
					printf_s("  (New Setting) \n");
					SetCursorPosition(gotoX, gotoY + 3);
					printf_s("                ");
					SetColor(BLACK, WHITE);
					SetCursorPosition(gotoX + 20, gotoY);
					printf_s("                \n");
					SetCursorPosition(gotoX + 20, gotoY + 1);
					printf_s("   Play Again   \n");
					SetCursorPosition(gotoX + 20, gotoY + 2);
					printf_s(" (Same Setting) \n");
					SetCursorPosition(gotoX + 20, gotoY + 3);
					printf_s("                ");
					SetColor(WHITE, BLACK);
				}
				else if (menuSelector == 2)
				{
					menuSelector--;
					SetColor(BLACK, GREEN);
					SetCursorPosition(gotoX + 20, gotoY);
					printf_s("                \n");
					SetCursorPosition(gotoX + 20, gotoY + 1);
					printf_s("   Play Again   \n");
					SetCursorPosition(gotoX + 20, gotoY + 2);
					printf_s(" (Same Setting) \n");
					SetCursorPosition(gotoX + 20, gotoY + 3);
					printf_s("                ");
					SetColor(BLACK, WHITE);
					SetCursorPosition(gotoX + 40, gotoY);
					printf_s("                \n");
					SetCursorPosition(gotoX + 40, gotoY + 1);
					printf_s("      Quit      \n");
					SetCursorPosition(gotoX + 40, gotoY + 2);
					printf_s("      Game      \n");
					SetCursorPosition(gotoX + 40, gotoY + 3);
					printf_s("                ");
					SetColor(WHITE, BLACK);
				}
			}
		}
		else if (keyinput == KEY_RIGHT)
		{
			if (gameStatus == SELECT_MAP_SHIP)
			{
				if (menuSelector == 0)
				{
					if (m_MapSize < 9)
					{
						m_MapSize += 1;
						SetCursorPosition(gotoX + 40, currentY);
						printf_s("¢¸ %d*%d ¢º", m_MapSize, m_MapSize);
					}
				}
				if (menuSelector >= 1 && menuSelector <= menuSize - 2)
				{
					if (m_NumShip[menuSelector - 1] < 3)
					{
						m_NumShip[menuSelector - 1] += 1;
						SetCursorPosition(gotoX + 40, currentY);
						printf_s("¢¸  %d  ¢º", m_NumShip[menuSelector - 1]);
					}
				}
			}
			if (gameStatus == WIN || gameStatus == LOSE)
			{
				if (menuSelector == 0)
				{
					menuSelector++;
					SetColor(BLACK, WHITE);
					SetCursorPosition(gotoX, gotoY);
					printf_s("                \n");
					SetCursorPosition(gotoX, gotoY + 1);
					printf_s("    To Title    \n");
					SetCursorPosition(gotoX, gotoY + 2);
					printf_s("  (New Setting) \n");
					SetCursorPosition(gotoX, gotoY + 3);
					printf_s("                ");
					SetColor(BLACK, GREEN);
					SetCursorPosition(gotoX + 20, gotoY);
					printf_s("                \n");
					SetCursorPosition(gotoX + 20, gotoY + 1);
					printf_s("   Play Again   \n");
					SetCursorPosition(gotoX + 20, gotoY + 2);
					printf_s(" (Same Setting) \n");
					SetCursorPosition(gotoX + 20, gotoY + 3);
					printf_s("                ");
					SetColor(WHITE, BLACK);
				}
				else if (menuSelector == 1)
				{
					menuSelector++;
					SetColor(BLACK, WHITE);
					SetCursorPosition(gotoX + 20, gotoY);
					printf_s("                \n");
					SetCursorPosition(gotoX + 20, gotoY + 1);
					printf_s("   Play Again   \n");
					SetCursorPosition(gotoX + 20, gotoY + 2);
					printf_s(" (Same Setting) \n");
					SetCursorPosition(gotoX + 20, gotoY + 3);
					printf_s("                ");
					SetColor(BLACK, GREEN);
					SetCursorPosition(gotoX + 40, gotoY);
					printf_s("                \n");
					SetCursorPosition(gotoX + 40, gotoY + 1);
					printf_s("      Quit      \n");
					SetCursorPosition(gotoX + 40, gotoY + 2);
					printf_s("      Game      \n");
					SetCursorPosition(gotoX + 40, gotoY + 3);
					printf_s("                ");
					SetColor(WHITE, BLACK);
				}
			}
		}
		else if (keyinput == ENTER)
		{
			if (gameStatus == SELECT_PLAYER || gameStatus == SET_SHIP || gameStatus == WIN || gameStatus == LOSE)
				break;
			else if (gameStatus == SELECT_MAP_SHIP)
			{
				if (okToStart == true && CheckEnoughSize() == true && menuSelector == menuSize - 1)
				{
					SetColor(WHITE, BLACK);
					break;
				}
			}
		}
	}
	return menuSelector;
}

bool GameInterface::CheckEnoughSize()
{
	int sumShipTile = m_NumShip[0] * 5 + m_NumShip[1] * 4 + m_NumShip[2] * 3 + m_NumShip[3] * 2;
	if (sumShipTile < m_MapSize * m_MapSize - 10)
		return true;
	else
		return false;
}


Position GameInterface::PositionToSetShip(ShipType shipType)
{
	int startPointX = 9;
	int startPointY = 11;
	Position tempPosition;
	tempPosition.m_X = startPointX;
	tempPosition.m_Y = startPointY;
	tempPosition.m_direction = DOWN;
	Position position;
	SetCursorPosition(startPointX, startPointY);
	m_GameRenderer->RenderShipOnMap(shipType, tempPosition);
	while (true)
	{
		int shipCoordX = (tempPosition.m_X - startPointX) / 4;
		int shipCoordY = (tempPosition.m_Y - startPointY) / 2;
		SetCursorPosition(tempPosition.m_X, tempPosition.m_Y);
		int keyinput;
		keyinput = _getch();
		if (keyinput == -32)
		{
			keyinput = _getch();
		}
		if (keyinput == KEY_DOWN || keyinput == KEY_UP || keyinput == KEY_LEFT || keyinput == KEY_RIGHT || keyinput == SPACE)
		{
			m_GameRenderer->RenderSpaceOnMap(shipType, tempPosition);
			if (keyinput == KEY_DOWN && tempPosition.m_Y < 2 * (m_MapSize - 1) + startPointY)
			{
				tempPosition.m_Y += 2;
			}
			else if (keyinput == KEY_UP && tempPosition.m_Y > startPointY)
			{
				tempPosition.m_Y -= 2;
			}

			else if (keyinput == KEY_LEFT && tempPosition.m_X > startPointX)
			{
				tempPosition.m_X -= 4;
			}
			else if (keyinput == KEY_RIGHT && tempPosition.m_X < 4 * (m_MapSize - 1) + startPointX)
			{
				tempPosition.m_X += 4;
			}
			else if (keyinput == SPACE)
			{
				tempPosition.m_direction = (Direction)(((int)tempPosition.m_direction + 1) % 4);
			}
			m_GameRenderer->RenderShipOnMap(shipType, tempPosition);
		}
		else if (keyinput == ENTER)
		{
			position.m_X = shipCoordX;
			position.m_Y = shipCoordY;
			position.m_direction = tempPosition.m_direction;
			break;
		}
	}
	return position;
}


Coordinate GameInterface::AttackInterface(int startPointX, int startPointY)
{
	int currentX = startPointX;
	int currentY = startPointY;
	Coordinate attackCoordinate;
	SetColor(WHITE, WHITE);
	SetCursorPosition(currentX, currentY);
	printf_s("  ");
	while (true)
	{
		int shipCoordX = (currentX - startPointX) / 4;
		int shipCoordY = (currentY - startPointY) / 2;
		SetCursorPosition(currentX, currentY);
		int keyinput;
		keyinput = _getch();
		if (keyinput == -32)
		{
			keyinput = _getch();
		}
		if (keyinput == KEY_DOWN || keyinput == KEY_RIGHT || keyinput == KEY_LEFT || keyinput == KEY_UP)
		{
			SetCursorAndColor(currentX, currentY, BLACK, BLACK);
			printf_s("  ");
			if (keyinput == KEY_DOWN && currentY < 2 * (m_MapSize - 1) + startPointY)
			{
				currentY += 2;
			}
			else if (keyinput == KEY_UP && currentY > startPointY)
			{
				currentY -= 2;
			}
			else if (keyinput == KEY_LEFT && currentX > startPointX)
			{
				currentX -= 4;
			}
			else if (keyinput == KEY_RIGHT && currentX < 4 * (m_MapSize - 1) + startPointX)
			{
				currentX += 4;
			}
			SetCursorAndColor(currentX, currentY, WHITE, WHITE);
			printf_s("  ");
		}
		else if (keyinput == SPACE)
		{
			attackCoordinate.m_X = rand() % m_MapSize;
			attackCoordinate.m_Y = rand() % m_MapSize;
			break;
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

int GameInterface::GetSumShip()
{
	int sumShip = 0;
	for (int i = 0; i < SHIPTYPECOUNT; ++i)
	{
		sumShip += m_NumShip[i];
	}
	return sumShip;
}

bool GameInterface::GameStartOrReset()
{
	bool startOrReset = true;
	int gotoX = (m_MapSize + 3) * 4 + 4;
	int gotoY = 7;
	SetColor(BLACK, GREEN);
	SetCursorPosition(gotoX + 2, gotoY + 12);
	printf_s("                  \n");
	SetCursorPosition(gotoX + 2, gotoY + 13);
	printf_s("    Start Game    \n");
	SetCursorPosition(gotoX + 2, gotoY + 14);
	printf_s("                  \n");
	SetColor(BLACK, WHITE);
	SetCursorPosition(gotoX + 2, gotoY + 17);
	printf_s("                  \n");
	SetCursorPosition(gotoX + 2, gotoY + 18);
	printf_s("       Reset      \n");
	SetCursorPosition(gotoX + 2, gotoY + 19);
	printf_s("                  ");
	while (true)
	{
		int keyinput;
		keyinput = _getch();
		if (keyinput == -32)
		{
			keyinput = _getch();
		}
		if (keyinput == KEY_DOWN && startOrReset == true)
		{
			SetColor(BLACK, WHITE);
			SetCursorPosition(gotoX + 2, gotoY + 12);
			printf_s("                  \n");
			SetCursorPosition(gotoX + 2, gotoY + 13);
			printf_s("    Start Game    \n");
			SetCursorPosition(gotoX + 2, gotoY + 14);
			printf_s("                  \n");
			SetColor(BLACK, DARK_RED);
			SetCursorPosition(gotoX + 2, gotoY + 17);
			printf_s("                  \n");
			SetCursorPosition(gotoX + 2, gotoY + 18);
			printf_s("       Reset      \n");
			SetCursorPosition(gotoX + 2, gotoY + 19);
			printf_s("                  ");
			startOrReset = false; //Reset
		}
		else if (keyinput == KEY_UP && startOrReset == false)
		{
			SetColor(BLACK, GREEN);
			SetCursorPosition(gotoX + 2, gotoY + 12);
			printf_s("                  \n");
			SetCursorPosition(gotoX + 2, gotoY + 13);
			printf_s("    Start Game    \n");
			SetCursorPosition(gotoX + 2, gotoY + 14);
			printf_s("                  \n");
			SetColor(BLACK, WHITE);
			SetCursorPosition(gotoX + 2, gotoY + 17);
			printf_s("                  \n");
			SetCursorPosition(gotoX + 2, gotoY + 18);
			printf_s("       Reset      \n");
			SetCursorPosition(gotoX + 2, gotoY + 19);
			printf_s("                  ");
			startOrReset = true; //Start
		}
		else if (keyinput == ENTER)
		{
			break;
		}
	}
	SetColor(WHITE, BLACK);
	return startOrReset;
}

