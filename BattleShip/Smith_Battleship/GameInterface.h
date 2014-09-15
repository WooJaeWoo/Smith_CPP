#pragma once

class GameRenderer;
class Map;

class GameInterface
{
public:
	GameInterface();
	~GameInterface();

	void					InitializeInterface();
	void					ResetInterface();
	void					DefaultInterface();

	void					AttachInterface(GameStatus gamestatus);
	Coordinate				AttackInterface(int startPointX, int startPointY);

	GamePlayType			GetGameType() { return m_GameType; }
	int						GetMapSize() { return m_MapSize; }
	std::vector<int>		GetNumShip() { return m_NumShip; }
	bool					GetSetOption() { return m_ManualOrRandom; }
	GameRenderer*			GetGameRenderer() { return m_GameRenderer; }
	int						GetLastMenu() { return m_LastMenu; }

	Position				PositionToSetShip(ShipType shipType);
	bool					GameStartOrReset();

private:
	GameRenderer*			m_GameRenderer;
	GamePlayType			m_GameType;
	int						m_MapSize;
	std::vector<int>		m_NumShip;
	bool					m_ManualOrRandom;
	int						m_LastMenu;

	int						MenuSelect(int menuSize, int gotoX, int gotoY, int currentY, GameStatus gameStatus);
	bool					CheckEnoughSize();
	int						GetSumShip();
};

