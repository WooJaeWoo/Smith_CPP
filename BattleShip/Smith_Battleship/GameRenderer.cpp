#include "stdafx.h"
#include "GameRenderer.h"
#include "Map.h"

GameRenderer::GameRenderer()
{
	m_MapSize = 8;
}


GameRenderer::~GameRenderer()
{
}

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void GameRenderer::InitializeRenderer()
{
	m_MapSize = 8;
}

void GameRenderer::ResetRenderer()
{
}

void GameRenderer::DefaultRenderer()
{
	m_MapSize = 8;
}

void GameRenderer::RenderPages(GameStatus gameStatus, GamePlayType gameType)
{
	int mapWidth = (m_MapSize + 3) * 4;
	int mapHeight = (m_MapSize + 2) * 2 + 8;
	int menuSpace = 40;
	int gotoX = mapWidth + 2;
	int gotoY = 10;
	SetColor(WHITE, BLACK);
	system("cls");
	switch (gameStatus)
	{
	case TITLE:
		SetConsoleSize(82, 13);
		RenderBattleshipTitle();
		RenderFiller(82, 81, 7);
		SetColor(GRAY, BLACK);
		printf_s("\n   SMITH GAMES \t\t\t\t\t\t\t\tVer 1.5\n");
		break;
	case SELECT_PLAYER:
		SetConsoleSize(62, 27);
		RenderSetting();
		RenderFiller(62, 61, 7);
		break;
	case SELECT_MAP_SHIP:
		SetConsoleSize(62, 34);
		RenderSetting();
		RenderFiller(62, 61, 7);
		break;
	case SET_SHIP:
		SetConsoleSize(mapWidth + menuSpace, mapHeight + 6);
		RenderSetting();
		RenderFiller(mapWidth + menuSpace, 61, 7);
		SetColor(WHITE, BLACK);
		RenderMap(4, 9);
		SetCursorAndColor(6, mapHeight + 1, BLACK, WHITE);
		printf_s(" Remain ");
		break;
	case GAMEPLAY:
		menuSpace = 25;
		SetConsoleSize(mapWidth * 2 + menuSpace, mapHeight + 5);
		RenderGamePlay();
		RenderFiller(mapWidth * 2 + menuSpace, 74, 7);
		RenderMap(mapWidth + menuSpace, 9);
		if (gameType != PVP_PLAY)
		{
			SetCursorPosition(mapWidth + menuSpace + (mapWidth / 2) - 6, mapHeight);
			printf_s("< My Map >");
		}
		else
		{
			SetCursorPosition(mapWidth + menuSpace + (mapWidth / 2) - 6, mapHeight);
			printf_s("< Player 2 >");
		}
		RenderMap(4, 9);
		if (gameType != PVP_PLAY)
		{
			SetCursorPosition(mapWidth / 2 - 6, mapHeight);
			printf_s("< Enemy Map >");
		}
		else
		{
			SetCursorPosition(mapWidth / 2 - 6, mapHeight);
			printf_s("< Player 1 >");
		}
		SetCursorPosition(gotoX, gotoY);
		printf_s("┌─  Result  ─┐");
		SetCursorPosition(gotoX, gotoY + 1);
		printf_s("│              │");
		SetCursorPosition(gotoX, gotoY + 2);
		printf_s("│              │");
		SetCursorPosition(gotoX, gotoY + 3);
		printf_s("│              │");
		SetCursorPosition(gotoX, gotoY + 4);
		printf_s("└───────┘");
		SetCursorPosition(gotoX, gotoY + 6);
		printf_s("■ SMITH  GAMES ■");
		SetCursorPosition(gotoX, gotoY + 8);
		printf_s("┌── turn ──┐");
		SetCursorPosition(gotoX, gotoY + 9);
		printf_s("│              │");
		SetCursorPosition(gotoX, gotoY + 10);
		printf_s("│       0      │");
		SetCursorPosition(gotoX, gotoY + 11);
		printf_s("│              │");
		SetCursorPosition(gotoX, gotoY + 12);
		printf_s("└───────┘");
		break;
	case WIN:
		SetConsoleSize(62, 18);
		RenderWin();
		RenderFiller(62, 61, 7);
		if (gameType == NET_PLAY)
		{
			int subgotoX = 12;
			SetCursorAndColor(23, 8, WHITE, BLACK);
			printf_s("NETWORK 대전 결과");
			SetCursorAndColor(subgotoX + 4, 9, LIGHT_GRAY, RED);
			printf_s("      ");
			SetCursorPosition(subgotoX + 4, 10);
			printf_s("  정  ");
			SetCursorPosition(subgotoX + 4, 11);
			printf_s("      ");
			SetCursorAndColor(subgotoX + 12, 9, GRAY, BLUE);
			printf_s("      ");
			SetCursorPosition(subgotoX + 12, 10);
			printf_s("  신  ");
			SetCursorPosition(subgotoX + 12, 11);
			printf_s("      ");
			SetCursorAndColor(subgotoX + 20, 9, DARK_RED, YELLOW);
			printf_s("      ");
			SetCursorPosition(subgotoX + 20, 10);
			printf_s("  승  ");
			SetCursorPosition(subgotoX + 20, 11);
			printf_s("      ");
			SetCursorAndColor(subgotoX + 28, 9, BLACK, GREEN);
			printf_s("      ");
			SetCursorPosition(subgotoX + 28, 10);
			printf_s("  리  ");
			SetCursorPosition(subgotoX + 28, 11);
			printf_s("      ");
		}
		break;
	case LOSE:
		SetConsoleSize(67, 18);
		RenderLose();
		RenderFiller(67, 66, 7);
		break;
	}
	SetColor(WHITE, BLACK);
}


//Functions Rendering Title Elements
void GameRenderer::RenderBattleshipTitle()
{
	SetColor(BLACK, WHITE);
	printf_s("                                                                                 \n");
	printf_s("  ■■■     ■  ■■■■ ■■■■ ■     ■■■  ■■■ ■    ■ ■■■ ■■■  \n");
	printf_s("  ■   ■   ■■    ■       ■    ■     ■     ■      ■    ■   ■   ■   ■ \n");
	printf_s("  ■■■   ■  ■   ■       ■    ■     ■■■  ■■   ■■■■   ■   ■■■  \n");
	printf_s("  ■   ■ ■■■■  ■       ■    ■     ■          ■ ■    ■   ■   ■      \n");
	printf_s("  ■■■  ■    ■  ■       ■    ■■■ ■■■ ■■■  ■    ■ ■■■ ■      \n");
	printf_s("                                                                                 ");
}

void GameRenderer::RenderSetting()
{
	SetColor(BLACK, WHITE);
	printf_s("                                                             \n");
	printf_s("   ■■■ ■■■ ■■■■ ■■■■ ■■■ ■    ■   ■■■  \n");
	printf_s("  ■      ■        ■       ■      ■   ■■  ■  ■    ■ \n");
	printf_s("   ■■   ■■■    ■       ■      ■   ■ ■ ■ ■        \n");
	printf_s("       ■ ■        ■       ■      ■   ■  ■■  ■  ■■ \n");
	printf_s("  ■■■  ■■■    ■       ■    ■■■ ■    ■   ■■ ■ \n");
	printf_s("                                                             ");
}

void GameRenderer::RenderGamePlay()
{
	SetColor(BLACK, WHITE);
	printf_s("                                                                          \n");
	printf_s("    ■■■     ■    ■■  ■■ ■■■■   ■■■  ■        ■  ■    ■ \n");
	printf_s("   ■    ■   ■■   ■ ■■ ■ ■         ■   ■ ■       ■■  ■  ■  \n");
	printf_s("  ■         ■  ■  ■  ■  ■ ■■■     ■■■  ■      ■  ■  ■■   \n");
	printf_s("   ■  ■■ ■■■■ ■      ■ ■         ■      ■     ■■■■  ■    \n");
	printf_s("    ■■ ■ ■    ■ ■      ■ ■■■■   ■      ■■■ ■    ■  ■    \n");
	printf_s("                                                                          ");
}

void GameRenderer::RenderWin()
{
	SetColor(BLACK, WHITE);
	printf_s("                                                             \n");
	printf_s("   ■    ■  ■■   ■    ■    ■      ■ ■■■ ■    ■   \n");
	printf_s("    ■  ■ ■    ■ ■    ■    ■      ■   ■   ■■  ■   \n");
	printf_s("     ■■  ■    ■ ■    ■    ■  ■  ■   ■   ■ ■ ■   \n");
	printf_s("      ■   ■    ■ ■    ■     ■ ■ ■    ■   ■  ■■   \n");
	printf_s("      ■     ■■    ■■■       ■  ■   ■■■ ■    ■   \n");
	printf_s("                                                             ");
}

void GameRenderer::RenderLose()
{
	SetColor(BLACK, WHITE);
	printf_s("                                                                  \n");
	printf_s("   ■    ■  ■■   ■    ■    ■       ■■    ■■■  ■■■   \n");
	printf_s("    ■  ■ ■    ■ ■    ■    ■     ■    ■ ■       ■       \n");
	printf_s("     ■■  ■    ■ ■    ■    ■     ■    ■  ■■■  ■■■   \n");
	printf_s("      ■   ■    ■ ■    ■    ■     ■    ■       ■ ■       \n");
	printf_s("      ■     ■■    ■■■     ■■■   ■■    ■■■  ■■■   \n");
	printf_s("                                                                  ");
}

void GameRenderer::RenderFiller(int consoleWidth, int titleWidth, int titleHeight)
{
	for (int j = 0; j < titleHeight; ++j)
	{
		SetCursorPosition(titleWidth, j);
		for (int i = 0; i < consoleWidth - titleWidth; ++i)
		{
			printf_s(" ");
		}
	}
}


//Functions Rendering Page Elements
void GameRenderer::RenderMap(int gotoX, int gotoY)
{
	SetColor(WHITE, BLACK);
	SetCursorPosition(0, gotoY);
	for (int j = 0; j < m_MapSize * 2 + 2; j++)
	{
		for (int k = 0; k < gotoX; k++)
		{
			printf_s(" ");
		}
		for (int i = 0; i < m_MapSize + 2; i++)
		{
			if (j == 0)
			{
				if (i == 0)
					printf_s("   ");
				else if (i == m_MapSize + 1)
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
				else if (i == m_MapSize + 1)
					printf_s("─┐");
				else if (i >= 2)
					printf_s("─┬");
			}
			else if (j == m_MapSize * 2 + 1)
			{
				if (i == 0)
					printf_s("   ");
				else if (i == 1)
					printf_s("└");
				else if (i == m_MapSize + 1)
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
				else if (i == m_MapSize + 1)
					printf_s("─┤");
				else if (i >= 2)
					printf_s("─┼");
			}
		}
		printf_s("\n");
	}
}

void GameRenderer::RenderShipOnMap(ShipType shiptype, Position position)
{
	for (int i = 0; i < GetMaxHP(shiptype); ++i)
	{
		if (position.m_X < FIRST_MAP_GOTOX || position.m_X > 4 * (m_MapSize - 1) + FIRST_MAP_GOTOX || position.m_Y < FIRST_MAP_GOTOY || position.m_Y > 2 * (m_MapSize - 1) + FIRST_MAP_GOTOY)
			return;
		SetCursorAndColor(position.m_X, position.m_Y, GetForeColor(shiptype), GetBackColor(shiptype));
		printf_s("%s", GetShipChar(shiptype).c_str());
		switch (position.m_direction)
		{
		case UP:
			position.m_Y -= 2;
			break;
		case DOWN:
			position.m_Y += 2;
			break;
		case LEFT:
			position.m_X -= 4;
			break;
		case RIGHT:
			position.m_X += 4;
			break;
		}
	}
}

void GameRenderer::RenderSpaceOnMap(ShipType shiptype, Position position)
{
	for (int i = 0; i < GetMaxHP(shiptype); ++i)
	{
		if (position.m_X < FIRST_MAP_GOTOX || position.m_X > 4 * (m_MapSize - 1) + FIRST_MAP_GOTOX || position.m_Y < FIRST_MAP_GOTOY || position.m_Y > 2 * (m_MapSize - 1) + FIRST_MAP_GOTOY)
			return;
		SetCursorAndColor(position.m_X, position.m_Y, BLACK, BLACK);
		printf_s("  ");
		switch (position.m_direction)
		{
		case UP:
			position.m_Y -= 2;
			break;
		case DOWN:
			position.m_Y += 2;
			break;
		case LEFT:
			position.m_X -= 4;
			break;
		case RIGHT:
			position.m_X += 4;
			break;
		}
	}
}


void GameRenderer::PrintTurn(int turn, int mapSize)
{
	if (turn < 0 || turn > mapSize * mapSize)
	{
		printf_s("ERROR: Invalid Turn");
		return;
	}
	SetColor(WHITE, BLACK);
	SetCursorPosition((mapSize + 3) * 4 + 4, 20);
	printf_s("      %2d      ", turn);
}

void GameRenderer::PrintResult(HitResult hitResult)
{
	SetColor(WHITE, BLACK);
	switch (hitResult)
	{
	case WRONG:
		SetCursorPosition((m_MapSize + 3) * 4 + 4, 12);
		printf_s("  Wrong Shot  ");
		SetCursorPosition((m_MapSize + 3) * 4 + 4, 13);
		printf_s("              ");
		break;
	case HIT:
		SetCursorPosition((m_MapSize + 3) * 4 + 4, 12);
		printf_s("     HIT!     ");
		SetCursorPosition((m_MapSize + 3) * 4 + 4, 13);
		printf_s("              ");
		break;
	case MISS:
		SetCursorPosition((m_MapSize + 3) * 4 + 4, 12);
		printf_s("     MISS     ");
		SetCursorPosition((m_MapSize + 3) * 4 + 4, 13);
		printf_s("              ");
		break;
	case DESTROY_AIRCRAFT:
		SetColor(RED, BLACK);
		SetCursorPosition((m_MapSize + 3) * 4 + 4, 12);
		printf_s("   Aircraft   ");
		SetCursorPosition((m_MapSize + 3) * 4 + 4, 13);
		printf_s("  Destroyed!  ");
		break;
	case DESTROY_BATTLESHIP:
		SetColor(BLUE, BLACK);
		SetCursorPosition((m_MapSize + 3) * 4 + 4, 12);
		printf_s("  Battleship  ");
		SetCursorPosition((m_MapSize + 3) * 4 + 4, 13);
		printf_s("  Destroyed!  ");
		break;
	case DESTROY_CRUISER:
		SetColor(YELLOW, BLACK);
		SetCursorPosition((m_MapSize + 3) * 4 + 4, 12);
		printf_s("   Cruiser    ");
		SetCursorPosition((m_MapSize + 3) * 4 + 4, 13);
		printf_s("  Destroyed!  ");
		break;
	case DESTROY_DESTROYER:
		SetColor(GREEN, BLACK);
		SetCursorPosition((m_MapSize + 3) * 4 + 4, 12);
		printf_s("  Destroyer   ");
		SetCursorPosition((m_MapSize + 3) * 4 + 4, 13);
		printf_s("  Destroyed!  ");
		break;
	}
}


//Set Console Attribution Functions
void GameRenderer::SetConsoleSize(int width, int height)
{
	std::stringstream makeThemOne;
	std::string str1 = "mode con:cols=";
	std::string str2 = " lines=";
	makeThemOne << str1 << width << str2 << height;
	std::string sumStr = makeThemOne.str();
	const char* resultStr = sumStr.c_str();
	system(resultStr);
}

void GameRenderer::SetCursorPosition(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(hConsole, pos);
}

void GameRenderer::SetColor(int fcolor, int bcolor)
{
	fcolor &= 0xf;
	bcolor &= 0xf;
	SetConsoleTextAttribute(hConsole, (bcolor << 4) | fcolor);
}

void GameRenderer::SetCursorAndColor(int x, int y, int fcolor, int bcolor)
{
	SetCursorPosition(x, y);
	SetColor(fcolor, bcolor);
}

