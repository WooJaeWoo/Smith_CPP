#pragma once

class GameRenderer;
class Map;

class GameInterface
{
public:
	GameInterface();
	~GameInterface();

	void					InitializeInterface();
	void					AttachInterface(GameStatus gamestatus);
	PlayerType				GetPlayerType() { return m_PlayerType; }
	int						GetMapSize() { return m_MapSize; }
	std::vector<int>		GetNumShip() { return m_NumShip; }
	GameRenderer*			GetGameRenderer() { return m_GameRenderer; }
	std::vector<Position>	GetShipPositions() { return m_Positions; }

private:
	GameRenderer*			m_GameRenderer;
	PlayerType				m_PlayerType;
	int						m_MapSize;
	std::vector<int>		m_NumShip;
	std::vector<Position>	m_Positions;
	Map*					m_P1_MyMap;
	Map*					m_P2_MyMap;

	int						MenuSelect(int menuSize, int gotoX, int gotoY, int currentY, GameStatus gameStatus);
	bool					CheckEnoughSize();
	void					SetShipInterface(ShipType shipType);
	Coordinate				AttackInterface();
	void					RenderRemain();
};

