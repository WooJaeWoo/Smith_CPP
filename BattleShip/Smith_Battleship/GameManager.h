#pragma once
#include "HeaderSet.h"

class GameRenderer;
class GameInterface;
class Player;
class Map;

class GameManager
{
public:
	GameManager();
	~GameManager();

	void					GameRun();

private:
	void					GameInitialize();
	void					MakePlayers();
	void					SendPositionAndSetShips();

	GameStatus				m_GameStatus;
	PlayerType				m_PlayerType;
	int						m_MapSize;
	std::vector<int>		m_NumShip;
	int						m_Turn;

	GameRenderer*			m_GameRenderer;
	GameInterface*			m_GameInterface;
	Player*					m_Player1;
	Player*					m_Player2;
};
