#pragma once
#include "stdafx.h"

class GameManager;
class Player;
class Map;


class GameEngine
{
public:
	GameEngine();
	~GameEngine();

	std::vector<int>	GetNumShip() { return m_NumShip; }
	void				SetNumShip(std::vector<int> numShip) { m_NumShip = numShip; }
	PlayerType			GetPlayerType() { return m_PlayerType; }


	void				GameRun();

private:
	GameManager*		m_GameManager;
	PlayerType			m_PlayerType;
	Player*				m_player1;
	Player*				m_player2;
	Map*				m_p1_MyMap;
	Map*				m_p1_EnemyMap;
	Map*				m_p2_MyMap;
	Map*				m_p2_EnemyMap;
	std::vector<int>	m_NumShip;

};

