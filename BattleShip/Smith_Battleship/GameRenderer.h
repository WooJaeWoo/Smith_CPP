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
	void				ResetRenderer();
	void				DefaultRenderer();

	void				RenderPages(GameStatus gameStatus, GamePlayType gameType);

	void				SetSizeOfMap(int MapSize) { m_MapSize = MapSize; }
	void				PrintResult(HitResult hitResult);
	void				PrintTurn(int turn, int mapSize);

	void				RenderShipOnMap(ShipType shiptype, Position position);
	void				RenderSpaceOnMap(ShipType shiptype, Position position);
	void				RenderMapStatus(int gotoX, int gotoY, MapStatus mapStatus);

	void				RenderWin();

	void				SetCursorPosition(int x, int y);
	void				SetColor(int fcolor, int bcolor);
	void				SetCursorAndColor(int x, int y, int fcolor, int bcolor);

private:
	void				RenderBattleshipTitle();
	void				RenderSetting();
	void				RenderGamePlay();
	void				RenderLose();
	void				RenderFiller(int consoleWidth, int titleWidth, int titleHeight);
	
	int					m_MapSize;
	void				RenderMap(int gotoX, int gotoY);

	void				SetConsoleSize(int width, int height);
};

