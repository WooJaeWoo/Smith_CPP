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
	void					ReadyToFight(Player* player);

	GameStatus				m_GameStatus;
	GamePlayType			m_GameType;
	int						m_MapSize;
	std::vector<int>		m_NumShip;
	int						m_Turn;

	GameRenderer*			m_GameRenderer;
	GameInterface*			m_GameInterface;
	Player*					m_Player1;
	Player*					m_Player2;
};
