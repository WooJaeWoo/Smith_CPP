#pragma once
#include <windows.h>

class Map;

class GameManager
{
public:
	GameManager();
	~GameManager();

	void					SetWindowTitle() { SetConsoleTitle(L"Smith's Battleship Game"); }
	void					RenderTitle();
	void					PlayerSettingPage();
	void					GameSettingPage();
	void					ShipSettingPage(Map& map);
	int						ShipSettingMenu(Map& map);
	void					GamePlayPage(Map& EnemyMap, Map& MyMap);

	Coordinate				AttakInterface();
	
	void					RenderMap(Map& map, int gotoX, int gotoY);
	void					RenderShipOnMap(ShipType shiptype, int gotoX, int gotoY, Direction direction);
	void					SetUpShipOnMap(ShipType shiptype, Map& map);
	void					RenderSpaceOnMap(ShipType shiptype, int gotoX, int gotoY, Direction direction);
	void					RenderRemain();
	void					PrintResult(HitResult hitResult);
	void					PrintTurn();

	void					RenderWin();
	void					RenderLose();


	PlayerType				GetPlayerType() { return m_PlayerType; }
	std::vector<int>		GetNumShip() { return m_NumShip; }
	int						GetMapSize() { return m_MapSize; }
	void					SetNumShip(std::vector<int> numShip) { m_NumShip = numShip; }

	void					GotoXY(int x, int y);
	void					SetConsoleSize(int widht, int height);
	void					SetColor(int fcolor, int bcolor);

	bool					ValidMapSize();
	bool					ValidPosition();

private:
	PlayerType				m_PlayerType;
	std::vector<int>		m_NumShip;
	int						m_MapSize;
	int						m_Turn;
	std::vector<Coordinate> m_startCoordinates;
	std::vector<Direction>	m_Directions;
};