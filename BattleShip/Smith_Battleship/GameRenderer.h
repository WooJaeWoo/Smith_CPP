#pragma once
#include "HeaderSet.h"

class Map;

class GameRenderer
{
public:
	GameRenderer();
	~GameRenderer();

	void				SetWindowTitle() { SetConsoleTitle(L"Smith's Battleship Game"); }
	void				InitializeRenderer();
	void				RenderPages(GameStatus gameStatus);

	void				SetSizeOfMap(int sizeOfMap) { m_MapSize = sizeOfMap; }
	void				PrintResult(HitResult hitResult);
	void				PrintTurn(int turn);

	void				RenderShipOnMap(ShipType shiptype, Position position);
	void				RenderSpaceOnMap(ShipType shiptype, Position position);
	void				RenderMapStatus(int gotoX, int gotoY, MapStatus mapStatus);

	void				SetCursorPosition(int x, int y);
	void				SetColor(int fcolor, int bcolor);
	void				SetCursorAndColor(int x, int y, int fcolor, int bcolor);

private:
	void				RenderBattleship();
	void				RenderSetting();
	void				RenderGamePlay();
	void				RenderWin();
	void				RenderLose();
	void				RenderFiller(int consoleWidth, int titleWidth);
	
	int					m_MapSize;
	void				RenderMap(int gotoX, int gotoY);

	void				SetConsoleSize(int width, int height);
};

