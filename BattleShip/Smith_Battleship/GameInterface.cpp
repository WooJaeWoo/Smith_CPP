#include "stdafx.h"
#include "GameInterface.h"
#include "GameRenderer.h"
#include "Map.h"

GameInterface::GameInterface()
{
	m_GameRenderer = new GameRenderer();
}

GameInterface::~GameInterface()
{
	delete m_GameRenderer;
}

void GameInterface::InitializeInterface()
{
	m_PlayerType = NONE;
	m_MapSize = 8;
	m_NumShip.clear();
	m_NumShip.push_back(1);
	m_NumShip.push_back(1);
	m_NumShip.push_back(1);
	m_NumShip.push_back(2);
	m_Positions.clear();
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
			m_GameRenderer->SetCursorPosition(gotoX, gotoY);
			printf_s("\t\t\t     PRESS ENTER KEY TO START      \t\t\t");
			Sleep(1000);
			m_GameRenderer->SetCursorPosition(gotoX, gotoY);
			printf_s("                                                                            ");
		}
		getchar();
		break;
	case SELECT_PLAYER:
		gotoX = 22;
		gotoY = 9;
		currentY = gotoY + 6;
		m_GameRenderer->SetColor(BLACK, WHITE);
		m_GameRenderer->SetCursorPosition(gotoX, gotoY);
		printf_s("                  \n");
		m_GameRenderer->SetCursorPosition(gotoX, gotoY + 1);
		printf_s("   PLAYER SELECT  \n");
		m_GameRenderer->SetCursorPosition(gotoX, gotoY + 2);
		printf_s("                  ");
		m_GameRenderer->SetColor(WHITE, BLACK);
		m_GameRenderer->SetCursorPosition(gotoX + 7, gotoY + 6);
		printf_s("VS Friend");
		m_GameRenderer->SetCursorPosition(gotoX + 7, gotoY + 9);
		printf_s("VS AI");
		m_GameRenderer->SetCursorPosition(gotoX + 7, gotoY + 12);
		printf_s("VS Network");
		m_GameRenderer->SetCursorPosition(gotoX - 1, currentY);
		printf_s("��");
		menuSelector = MenuSelect(3, gotoX, gotoY, currentY, gameStatus);
		if (menuSelector == 0)
		{
			m_PlayerType = PVP;
		}
		else if (menuSelector == 1)
		{
			m_PlayerType = AI;
		}
		else if (menuSelector == 2)
		{
			m_PlayerType = NETWORK;
		}
		break;
	case SELECT_MAP_SHIP:
		gotoX = 4;
		gotoY = 9;
		currentY = gotoY + 5;
		m_GameRenderer->SetColor(BLACK, WHITE);
		m_GameRenderer->SetCursorPosition(gotoX + 18, gotoY);
		printf_s("                  \n");
		m_GameRenderer->SetCursorPosition(gotoX + 18, gotoY + 1);
		printf_s("    SHIP SELECT   \n");
		m_GameRenderer->SetCursorPosition(gotoX + 18, gotoY + 2);
		printf_s("                  ");
		m_GameRenderer->SetColor(WHITE, BLACK);
		m_GameRenderer->SetCursorPosition(gotoX + 6, gotoY + 5);
		printf_s("Map size");
		m_GameRenderer->SetCursorPosition(gotoX + 6, gotoY + 8);
		printf_s("Aircraft Carrier");
		m_GameRenderer->SetCursorPosition(gotoX + 6, gotoY + 11);
		printf_s("Battleship");
		m_GameRenderer->SetCursorPosition(gotoX + 6, gotoY + 14);
		printf_s("Cruiser");
		m_GameRenderer->SetCursorPosition(gotoX + 6, gotoY + 17);
		printf_s("Destroyer");
		m_GameRenderer->SetColor(BLACK, WHITE);
		m_GameRenderer->SetCursorPosition(gotoX + 18, gotoY + 20);
		printf_s("                   \n");
		m_GameRenderer->SetCursorPosition(gotoX + 18, gotoY + 21);
		printf_s("      N E X T      \n");
		m_GameRenderer->SetCursorPosition(gotoX + 18, gotoY + 22);
		printf_s("                   ");
		m_GameRenderer->SetColor(WHITE, BLACK);
		m_GameRenderer->SetCursorPosition(gotoX + 40, gotoY + 5);
		printf_s("�� %d*%d ��", m_MapSize, m_MapSize);
		m_GameRenderer->SetCursorPosition(gotoX + 40, gotoY + 8);
		printf_s("��  %d  ��", m_NumShip[0]);
		m_GameRenderer->SetCursorPosition(gotoX + 40, gotoY + 11);
		printf_s("��  %d  ��", m_NumShip[1]);
		m_GameRenderer->SetCursorPosition(gotoX + 40, gotoY + 14);
		printf_s("��  %d  ��", m_NumShip[2]);
		m_GameRenderer->SetCursorPosition(gotoX + 40, gotoY + 17);
		printf_s("��  %d  ��", m_NumShip[3]);
		m_GameRenderer->SetCursorPosition(gotoX, currentY);
		printf_s("��");
		menuSelector = MenuSelect(6, gotoX, gotoY, currentY, gameStatus);
		break;
	case SET_SHIP:
		gotoX = (m_MapSize + 3) * 4 + 4;
		gotoY = 7;
		currentY = gotoY + 5;
		m_GameRenderer->SetCursorPosition(gotoX + 6, gotoY + 5);
		printf_s("Manual Set");
		m_GameRenderer->SetCursorPosition(gotoX + 6, gotoY + 8);
		printf_s("Random Set");
		m_GameRenderer->SetCursorPosition(gotoX, currentY);
		printf_s("��");
		m_GameRenderer->SetColor(BLACK, WHITE);
		m_GameRenderer->SetCursorPosition(gotoX + 2, gotoY + 12);
		printf_s("                  \n");
		m_GameRenderer->SetCursorPosition(gotoX + 2, gotoY + 13);
		printf_s("    Start Game    \n");
		m_GameRenderer->SetCursorPosition(gotoX + 2, gotoY + 14);
		printf_s("                  \n");
		m_GameRenderer->SetCursorPosition(gotoX + 2, gotoY + 17);
		printf_s("                  \n");
		m_GameRenderer->SetCursorPosition(gotoX + 2, gotoY + 18);
		printf_s("       Reset      \n");
		m_GameRenderer->SetCursorPosition(gotoX + 2, gotoY + 19);
		printf_s("                  ");
		m_GameRenderer->SetCursorPosition(15, (m_MapSize + 2) * 2 + 9);
		RenderRemain();
		menuSelector = MenuSelect(2, gotoX, gotoY, currentY, gameStatus);
		if (menuSelector == 0)
		{
			int shipType = 0;
			for (int i = 0;; ++i)
			{
				if (shipType == 4)
					break;
				if (m_NumShip[shipType] == 0)
				{
					shipType++;
				}
				else
				{
					SetShipInterface((ShipType)shipType);
				}
			}
		}
		else if (menuSelector == 1)
		{
			//RandomSet
		}
		m_GameRenderer->SetColor(WHITE, BLACK);
		break;
	case GAMEPLAY:
		AttackInterface();
		break;
	case WIN:

		break;
	case LOSE:
		break;
	}
}

int GameInterface::MenuSelect(int menuSize, int gotoX, int gotoY, int currentY, GameStatus gameStatus)
{
	int menuSelector = 0;
	bool okToStart = false;
	int sumShips = 0;
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
					m_GameRenderer->SetCursorPosition(gotoX, currentY);
					printf_s("  ");
					currentY += 3;
					menuSelector += 1;
					m_GameRenderer->SetCursorPosition(gotoX, currentY);
					printf_s("��");
				}
			}
			else if (gameStatus == SELECT_MAP_SHIP)
			{
				if (menuSelector >= 0 && menuSelector < menuSize - 2)
				{
					m_GameRenderer->SetCursorPosition(gotoX, currentY);
					printf_s("  ");
					currentY += 3;
					menuSelector += 1;
					m_GameRenderer->SetCursorPosition(gotoX, currentY);
					printf_s("��");
				}
				else if (menuSelector == menuSize - 2)
				{
					sumShips = 0;
					for (int i = 0; i < SHIPTYPECOUNT; i++)
					{
						sumShips += m_NumShip[i];
					}
					m_GameRenderer->SetCursorPosition(gotoX, currentY);
					printf_s("  ");
					currentY += 3;
					menuSelector += 1;
					if (sumShips == 0)
					{
						okToStart = false;
						m_GameRenderer->SetColor(BLACK, DARK_RED);
						m_GameRenderer->SetCursorPosition(gotoX + 18, gotoY + 20);
						printf_s("                   \n");
						m_GameRenderer->SetCursorPosition(gotoX + 18, gotoY + 21);
						printf_s("      No Ship      \n");
						m_GameRenderer->SetCursorPosition(gotoX + 18, gotoY + 22);
						printf_s("                   ");
					}
					else if (CheckEnoughSize() == false)
					{
						okToStart = false;
						m_GameRenderer->SetColor(BLACK, DARK_RED);
						m_GameRenderer->SetCursorPosition(gotoX + 18, gotoY + 20);
						printf_s("                   \n");
						m_GameRenderer->SetCursorPosition(gotoX + 18, gotoY + 21);
						printf_s("   Too Many Ships  \n");
						m_GameRenderer->SetCursorPosition(gotoX + 18, gotoY + 22);
						printf_s("                   ");
					}
					else
					{
						okToStart = true;
						m_GameRenderer->SetColor(BLACK, GREEN);
						m_GameRenderer->SetCursorPosition(gotoX + 18, gotoY + 20);
						printf_s("                   \n");
						m_GameRenderer->SetCursorPosition(gotoX + 18, gotoY + 21);
						printf_s("      N E X T      \n");
						m_GameRenderer->SetCursorPosition(gotoX + 18, gotoY + 22);
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
					m_GameRenderer->SetCursorPosition(gotoX, currentY);
					printf_s("  ");
					currentY -= 3;
					menuSelector -= 1;
					m_GameRenderer->SetCursorPosition(gotoX, currentY);
					printf_s("��");
				}
			}
			else if (gameStatus == SELECT_MAP_SHIP)
			{
				if (menuSelector >= 1 && menuSelector < menuSize - 1)
				{
					m_GameRenderer->SetCursorPosition(gotoX, currentY);
					printf_s("  ");
					currentY -= 3;
					menuSelector -= 1;
					m_GameRenderer->SetCursorPosition(gotoX, currentY);
					printf_s("��");
				}
				else if (menuSelector == menuSize - 1)
				{
					currentY -= 3;
					menuSelector -= 1;
					m_GameRenderer->SetColor(BLACK, WHITE);
					m_GameRenderer->SetCursorPosition(gotoX + 18, gotoY + 20);
					printf_s("                   \n");
					m_GameRenderer->SetCursorPosition(gotoX + 18, gotoY + 21);
					printf_s("      N E X T      \n");
					m_GameRenderer->SetCursorPosition(gotoX + 18, gotoY + 22);
					printf_s("                   ");
					m_GameRenderer->SetColor(WHITE, BLACK);
					m_GameRenderer->SetCursorPosition(gotoX, currentY);
					printf_s("��");
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
						m_GameRenderer->SetCursorPosition(gotoX + 40, currentY);
						printf_s("�� %d*%d ��", m_MapSize, m_MapSize);
					}
				}
				else if (menuSelector >= 1 && menuSelector <= menuSize - 2)
				{
					if (m_NumShip[menuSelector - 1] > 0)
					{
						m_NumShip[menuSelector - 1] -= 1;
						m_GameRenderer->SetCursorPosition(gotoX + 40, currentY);
						printf_s("��  %d  ��", m_NumShip[menuSelector - 1]);
					}
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
						m_GameRenderer->SetCursorPosition(gotoX + 40, currentY);
						printf_s("�� %d*%d ��", m_MapSize, m_MapSize);
					}
				}
				if (menuSelector >= 1 && menuSelector <= menuSize - 2)
				{
					if (m_NumShip[menuSelector - 1] < 3)
					{
						m_NumShip[menuSelector - 1] += 1;
						m_GameRenderer->SetCursorPosition(gotoX + 40, currentY);
						printf_s("��  %d  ��", m_NumShip[menuSelector - 1]);
					}
				}
			}
		}
		else if (keyinput == ENTER)
		{
			if (gameStatus == SELECT_PLAYER || gameStatus == SET_SHIP)
				break;
			else if (gameStatus == SELECT_MAP_SHIP)
			{
				if (okToStart == true && CheckEnoughSize() == true && menuSelector == menuSize - 1)
				{
					m_GameRenderer->SetColor(WHITE, BLACK);
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


void GameInterface::RenderRemain()
{
	int sumShip = 0;
	m_GameRenderer->SetCursorAndColor(15, (m_MapSize + 2) * 2 + 9, BLACK, BLACK);
	for (int i = 0; i < SHIPTYPECOUNT; ++i)
	{
		sumShip += m_NumShip[i];
	}
	for (int i = 0; i < sumShip + 1; ++i)
	{
		printf_s("   ");
	}
	m_GameRenderer->SetCursorPosition(15, (m_MapSize + 2) * 2 + 9);
	m_GameRenderer->SetColor(WHITE, BLACK);
	printf_s(" ");
	for (int i = 0; i < SHIPTYPECOUNT; i++)
	{
		for (int j = 0; j < m_NumShip[i]; j++)
		{
			m_GameRenderer->SetColor(GetForeColor((ShipType)i), GetBackColor((ShipType)i));
			printf_s("%s", GetShipChar((ShipType)i).c_str());
			m_GameRenderer->SetColor(WHITE, BLACK);
			printf_s(" ");
		}
	}
}

void GameInterface::SetShipInterface(ShipType shipType)
{
	int startPointX = 9;
	int startPointY = 11;
	Position tempPosition;
	tempPosition.m_X = startPointX;
	tempPosition.m_Y = startPointY;
	tempPosition.m_direction = DOWN;
	Position position;
	m_GameRenderer->SetCursorPosition(startPointX, startPointY);
	m_GameRenderer->RenderShipOnMap(shipType, tempPosition);
	while (true)
	{
		int shipCoordX = (tempPosition.m_X - startPointX) / 4;
		int shipCoordY = (tempPosition.m_Y - startPointY) / 2;
		m_GameRenderer->SetCursorPosition(tempPosition.m_X, tempPosition.m_Y);
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
			if (m_P1_MyMap->IsNOTHING(position, shipType) == true)
			{
				m_Positions.push_back(position);
				m_P1_MyMap->SetMapStatus(position, (MapStatus)((int)shipType + 1), shipType);
				m_GameRenderer->RenderMapStatus(9, 11, *m_P1_MyMap);
				m_NumShip[(int)shipType]--;
				RenderRemain(); //���� ������ for�� ����
				break;
			}
		}
	}
}


Coordinate GameInterface::AttackInterface()
{
	int startPointX = 9;
	int startPointY = 11;
	int currentX = startPointX;
	int currentY = startPointY;
	Coordinate attackCoordinate;
	m_GameRenderer->SetColor(WHITE, WHITE);
	m_GameRenderer->SetCursorPosition(currentX, currentY);
	printf_s("  ");
	while (true)
	{
		int shipCoordX = (currentX - startPointX) / 4;
		int shipCoordY = (currentY - startPointY) / 2;
		m_GameRenderer->SetCursorPosition(currentX, currentY);
		int keyinput;
		keyinput = _getch();
		if (keyinput == -32)
		{
			keyinput = _getch();
		}
		if (keyinput == KEY_DOWN || keyinput == KEY_RIGHT || keyinput == KEY_LEFT || keyinput == KEY_UP)
		{
			m_GameRenderer->SetCursorAndColor(currentX, currentY, BLACK, BLACK);
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
			m_GameRenderer->SetCursorAndColor(currentX, currentY, WHITE, WHITE);
			printf_s("  ");
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
