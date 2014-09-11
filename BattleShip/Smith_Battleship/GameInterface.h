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
	bool					GetSetOption() { return m_ManualOrRandom; }
	GameRenderer*			GetGameRenderer() { return m_GameRenderer; }
	Position				PositionToSetShip(ShipType shipType);
	Coordinate				AttackInterface();
	bool					GameStartOrReset();

private:
	GameRenderer*			m_GameRenderer;
	PlayerType				m_PlayerType;
	int						m_MapSize;
	std::vector<int>		m_NumShip;
	bool					m_ManualOrRandom;

	int						MenuSelect(int menuSize, int gotoX, int gotoY, int currentY, GameStatus gameStatus);
	bool					CheckEnoughSize();
	int						GetSumShip();
};

