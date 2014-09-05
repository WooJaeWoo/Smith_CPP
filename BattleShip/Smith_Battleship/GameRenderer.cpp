#include "stdafx.h"
#include "GameRenderer.h"


GameRenderer::GameRenderer()
{
	m_SizeOfMap = 9;
	m_turn = 14;
	m_HitResult = HIT;
	///////////////////////////////////
	/// Change Value at GameManager ///
	///////////////////////////////////
}


GameRenderer::~GameRenderer()
{
}

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void GameRenderer::RenderPages(GameStatus gameStatus)
{
	int mapWidth = (m_SizeOfMap + 3) * 4;
	int mapHeight = (m_SizeOfMap + 2) * 2 + 8;
	int menuSpace = 40;
	int gotoX = mapWidth + 2;
	int gotoY = 10;

	system("cls");
	switch (gameStatus)
	{
	case TITLE:
		SetConsoleSize(82, 12);
		RenderBattleship();
		RenderFiller(82, 81);
		SetColor(GRAY, BLACK);
		printf_s("\n  SMITH GAMES \t\t\t\t\t\t\t\t   ver1.0\n");
		while (!_kbhit())
		{
			Sleep(600);
			SetCursorPosition(0, 10);
			printf_s("\t\t\t     PRESS ENTER KEY TO START      \t\t\t");
			Sleep(1000);
			SetCursorPosition(0, 10);
			printf_s("                                                                            ");
		}
		break;
	case SELECT_PLAYER:
		SetConsoleSize(62, 27);
		RenderSetting();
		RenderFiller(62, 61);
		break;
	case SELECT_MAP_SHIP:
		SetConsoleSize(62, 34);
		RenderSetting();
		RenderFiller(62, 61);
		break;
	case SET_SHIP:
		SetConsoleSize(mapWidth + menuSpace, mapHeight + 5);
		RenderSetting();
		RenderFiller(mapWidth + menuSpace, 61);
		SetColor(WHITE, BLACK);
		RenderMap(4, 9);
		break;
	case GAMEPLAY:
		menuSpace = 25;
		SetConsoleSize(mapWidth * 2 + menuSpace, mapHeight + 5);
		RenderGamePlay();
		RenderFiller(mapWidth * 2 + menuSpace, 74);
		RenderMap(mapWidth + menuSpace, 9);
		SetCursorPosition(mapWidth + menuSpace + (mapWidth / 2) - 6, mapHeight);
		printf_s("< My Map >");
		RenderMap(4, 9);
		SetCursorPosition(mapWidth / 2 - 6, mapHeight);
		printf_s("< Enemy Map >");
		SetCursorPosition(gotoX, gotoY);
		printf_s("忙式  Result  式忖");
		SetCursorPosition(gotoX, gotoY + 1);
		printf_s("弛              弛");
		SetCursorPosition(gotoX, gotoY + 2);
		printf_s("弛              弛");
		SetCursorPosition(gotoX, gotoY + 3);
		printf_s("弛              弛");
		SetCursorPosition(gotoX, gotoY + 4);
		printf_s("戌式式式式式式式戎");
		SetCursorPosition(gotoX, gotoY + 6);
		printf_s("﹥ SMITH  GAMES ﹥");
		SetCursorPosition(gotoX, gotoY + 8);
		printf_s("忙式式 turn 式式忖");
		SetCursorPosition(gotoX, gotoY + 9);
		printf_s("弛              弛");
		SetCursorPosition(gotoX, gotoY + 10);
		printf_s("弛              弛");
		SetCursorPosition(gotoX, gotoY + 11);
		printf_s("弛              弛");
		SetCursorPosition(gotoX, gotoY + 12);
		printf_s("戌式式式式式式式戎");
		PrintResult();
		PrintTurn();
		break;

	case WIN:
		SetConsoleSize(62, 12);
		RenderWin();
		RenderFiller(62, 61);
		break;
	case LOSE:
		SetConsoleSize(67, 12);
		RenderLose();
		RenderFiller(67, 66);
		break;
	}
	SetColor(WHITE, BLACK);
}


//Functions Rendering Title Elements
void GameRenderer::RenderBattleship()
{
	SetColor(BLACK, WHITE);
	printf_s("                                                                                 \n");
	printf_s("  ﹥﹥﹥     ﹥  ﹥﹥﹥﹥ ﹥﹥﹥﹥ ﹥     ﹥﹥﹥  ﹥﹥﹥ ﹥    ﹥ ﹥﹥﹥ ﹥﹥﹥  \n");
	printf_s("  ﹥   ﹥   ﹥﹥    ﹥       ﹥    ﹥     ﹥     ﹥      ﹥    ﹥   ﹥   ﹥   ﹥ \n");
	printf_s("  ﹥﹥﹥   ﹥  ﹥   ﹥       ﹥    ﹥     ﹥﹥﹥  ﹥﹥   ﹥﹥﹥﹥   ﹥   ﹥﹥﹥  \n");
	printf_s("  ﹥   ﹥ ﹥﹥﹥﹥  ﹥       ﹥    ﹥     ﹥          ﹥ ﹥    ﹥   ﹥   ﹥      \n");
	printf_s("  ﹥﹥﹥  ﹥    ﹥  ﹥       ﹥    ﹥﹥﹥ ﹥﹥﹥ ﹥﹥﹥  ﹥    ﹥ ﹥﹥﹥ ﹥      \n");
	printf_s("                                                                                 ");
}

void GameRenderer::RenderSetting()
{
	SetColor(BLACK, WHITE);
	printf_s("                                                             \n");
	printf_s("   ﹥﹥﹥ ﹥﹥﹥ ﹥﹥﹥﹥ ﹥﹥﹥﹥ ﹥﹥﹥ ﹥    ﹥   ﹥﹥﹥  \n");
	printf_s("  ﹥      ﹥        ﹥       ﹥      ﹥   ﹥﹥  ﹥  ﹥    ﹥ \n");
	printf_s("   ﹥﹥   ﹥﹥﹥    ﹥       ﹥      ﹥   ﹥ ﹥ ﹥ ﹥        \n");
	printf_s("       ﹥ ﹥        ﹥       ﹥      ﹥   ﹥  ﹥﹥  ﹥  ﹥﹥ \n");
	printf_s("  ﹥﹥﹥  ﹥﹥﹥    ﹥       ﹥    ﹥﹥﹥ ﹥    ﹥   ﹥﹥ ﹥ \n");
	printf_s("                                                             ");
}

void GameRenderer::RenderGamePlay()
{
	SetColor(BLACK, WHITE);
	printf_s("                                                                          \n");
	printf_s("    ﹥﹥﹥     ﹥    ﹥﹥  ﹥﹥ ﹥﹥﹥﹥   ﹥﹥﹥  ﹥        ﹥  ﹥    ﹥ \n");
	printf_s("   ﹥    ﹥   ﹥﹥   ﹥ ﹥﹥ ﹥ ﹥         ﹥   ﹥ ﹥       ﹥﹥  ﹥  ﹥  \n");
	printf_s("  ﹥         ﹥  ﹥  ﹥  ﹥  ﹥ ﹥﹥﹥     ﹥﹥﹥  ﹥      ﹥  ﹥  ﹥﹥   \n");
	printf_s("   ﹥  ﹥﹥ ﹥﹥﹥﹥ ﹥      ﹥ ﹥         ﹥      ﹥     ﹥﹥﹥﹥  ﹥    \n");
	printf_s("    ﹥﹥ ﹥ ﹥    ﹥ ﹥      ﹥ ﹥﹥﹥﹥   ﹥      ﹥﹥﹥ ﹥    ﹥  ﹥    \n");
	printf_s("                                                                          ");
}

void GameRenderer::RenderWin()
{
	SetColor(BLACK, WHITE);
	printf_s("                                                             \n");
	printf_s("   ﹥    ﹥  ﹥﹥   ﹥    ﹥    ﹥      ﹥ ﹥﹥﹥ ﹥    ﹥   \n");
	printf_s("    ﹥  ﹥ ﹥    ﹥ ﹥    ﹥    ﹥      ﹥   ﹥   ﹥﹥  ﹥   \n");
	printf_s("     ﹥﹥  ﹥    ﹥ ﹥    ﹥    ﹥  ﹥  ﹥   ﹥   ﹥ ﹥ ﹥   \n");
	printf_s("      ﹥   ﹥    ﹥ ﹥    ﹥     ﹥ ﹥ ﹥    ﹥   ﹥  ﹥﹥   \n");
	printf_s("      ﹥     ﹥﹥    ﹥﹥﹥       ﹥  ﹥   ﹥﹥﹥ ﹥    ﹥   \n");
	printf_s("                                                             ");
}

void GameRenderer::RenderLose()
{
	SetColor(BLACK, WHITE);
	printf_s("                                                                  \n");
	printf_s("   ﹥    ﹥  ﹥﹥   ﹥    ﹥    ﹥       ﹥﹥    ﹥﹥﹥  ﹥﹥﹥   \n");
	printf_s("    ﹥  ﹥ ﹥    ﹥ ﹥    ﹥    ﹥     ﹥    ﹥ ﹥       ﹥       \n");
	printf_s("     ﹥﹥  ﹥    ﹥ ﹥    ﹥    ﹥     ﹥    ﹥  ﹥﹥﹥  ﹥﹥﹥   \n");
	printf_s("      ﹥   ﹥    ﹥ ﹥    ﹥    ﹥     ﹥    ﹥       ﹥ ﹥       \n");
	printf_s("      ﹥     ﹥﹥    ﹥﹥﹥     ﹥﹥﹥   ﹥﹥    ﹥﹥﹥  ﹥﹥﹥   \n");
	printf_s("                                                                  ");
}

void GameRenderer::RenderFiller(int consoleWidth, int titleWidth)
{
	for (int j = 0; j < 7; ++j)
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
	for (int j = 0; j < m_SizeOfMap * 2 + 2; j++)
	{
		for (int k = 0; k < gotoX; k++)
		{
			printf_s(" ");
		}
		for (int i = 0; i < m_SizeOfMap + 2; i++)
		{
			if (j == 0)
			{
				if (i == 0)
					printf_s("   ");
				else if (i == m_SizeOfMap + 1)
					printf_s("");
				else
					printf_s("   %c", '1' + i - 1);
			}
			else if (j == 1)
			{
				if (i == 0)
					printf_s("   ");
				else if (i == 1)
					printf_s("忙");
				else if (i == m_SizeOfMap + 1)
					printf_s("式忖");
				else if (i >= 2)
					printf_s("式成");
			}
			else if (j == m_SizeOfMap * 2 + 1)
			{
				if (i == 0)
					printf_s("   ");
				else if (i == 1)
					printf_s("戌");
				else if (i == m_SizeOfMap + 1)
					printf_s("式戎");
				else if (i >= 2)
					printf_s("式扛");
			}
			else if (j % 2 == 0)
			{
				if (i == 0)
					printf_s(" %c ", 'A' + (j / 2) - 1);
				else
					printf_s("弛  ");
			}
			else // j % 2 == 1
			{
				if (i == 0)
					printf_s("   ");
				else if (i == 1)
					printf_s("戍");
				else if (i == m_SizeOfMap + 1)
					printf_s("式扣");
				else if (i >= 2)
					printf_s("式托");
			}
		}
		printf_s("\n");
	}
}

void GameRenderer::PrintTurn()
{
	SetColor(WHITE, BLACK);
	SetCursorPosition((m_SizeOfMap + 3) * 4 + 4, 20);
	printf_s("      %2d      ", m_turn);
}

void GameRenderer::PrintResult()
{
	switch (m_HitResult)
	{
	case HIT:
		SetCursorPosition((m_SizeOfMap + 3) * 4 + 4, 12);
		printf_s("     HIT!     ");
		break;
	case MISS:
		SetCursorPosition((m_SizeOfMap + 3) * 4 + 4, 12);
		printf_s("     MISS     ");
		break;
	case DESTROY_AIRCRAFT:
		SetCursorPosition((m_SizeOfMap + 3) * 4 + 4, 12);
		printf_s("   Aircraft   ");
		SetCursorPosition((m_SizeOfMap + 3) * 4 + 4, 13);
		printf_s("  Destroyed!  ");
		break;
	case DESTROY_BATTLESHIP:
		SetCursorPosition((m_SizeOfMap + 3) * 4 + 4, 12);
		printf_s("  Battleship  ");
		SetCursorPosition((m_SizeOfMap + 3) * 4 + 4, 13);
		printf_s("  Destroyed!  ");
		break;
	case DESTROY_CRUISER:
		SetCursorPosition((m_SizeOfMap + 3) * 4 + 4, 12);
		printf_s("   Cruiser    ");
		SetCursorPosition((m_SizeOfMap + 3) * 4 + 4, 13);
		printf_s("  Destroyed!  ");
		break;
	case DESTROY_DESTROYER:
		SetCursorPosition((m_SizeOfMap + 3) * 4 + 4, 12);
		printf_s("  Destroyer   ");
		SetCursorPosition((m_SizeOfMap + 3) * 4 + 4, 13);
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
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
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

