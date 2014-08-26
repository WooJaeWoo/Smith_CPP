#pragma once
#include <windows.h>

class Map;

class GameRender
{
public:
	GameRender();
	~GameRender();

	void					SetWindowTitle() { SetConsoleTitle(L"Smith's Battleship Game"); }
	void					RenderTitle();
	void					RenderPlayerSettingPage();
	void					RenderGameSettingPage(Map& map);
	void					RenderShipSettingPage(Map& map);
	void					ShipSettingMenu(Map& map);
	void					RenderMap(Map& map, int gotoX, int gotoY);
	void					RenderShipOnMap(ShipType shiptype, int gotoX, int gotoY, Direction direction);
	void					SetUpShipOnMap(ShipType shiptype, Map& map);
	void					RenderSpaceOnMap(ShipType shiptype, int gotoX, int gotoY, Direction direction);
	void					RenderRemain();

	PlayerType				GetPlayerType() { return m_PlayerType; }
	std::vector<int>		GetNumShip() { return m_NumShip; }
	int						GetMapSize() { return m_MapSize; }
	void					SetNumShip(std::vector<int> numShip) { m_NumShip = numShip; }

	void					GotoXY(int x, int y);
	void					SetConsoleSize(int widht, int height);
	void					SetColor(int fcolor, int bcolor);

	bool					ValidMapSize();

private:
	PlayerType				m_PlayerType;
	std::vector<int>		m_NumShip;
	int						m_MapSize;
};