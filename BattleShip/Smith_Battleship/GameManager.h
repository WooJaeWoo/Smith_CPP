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
	void					InitializeGame();
	void					ResetGame();
	void					DefaultGame();

	void					SetPlayerType();
	void					MakeMapAndShip();
	void					ReadyToFight(Player* player);

	bool					AttackFlow(Player* player1, Player* player2);
	void					PVPSetShip();
	void					PVASetShip();
	void					AVNSetShip();
	int						PVPGameFlow();
	int						PVAGameFlow();
	//void					AVNGameFlow();

	void					WriteGameResult(int who);
	bool					LastMenuDecision(int lastMenu);

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
