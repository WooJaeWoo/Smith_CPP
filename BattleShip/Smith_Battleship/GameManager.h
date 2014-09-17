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
	void					DefaultGameSetting();

	void					SetPlayerType();
	void					MakeMapAndShip();
	void					ReadyToFight(Player* player);
	bool					AttackFlow(Player* attacker, Player* defender);

	void					PVP_PlaySetShip();
	void					AI_PlaySetShip();
	void					NET_PlaySetShip();
	int						PVP_PlayGameFlow();
	int						AI_PlayGameFlow();
	void					NET_PlayGameFlow();

	Position				ConvertPosionForNET(ShipType shipType, Position position);

	void					WriteGameResult(int who);
	bool					LastMenuDecision(int lastMenu);

	GameStatus				m_GameStatus;
	GamePlayType			m_GameType;
	int						m_MapSize;
	std::vector<int>		m_NumShip;
	std::vector<Position>	m_ShipPositions;
	int						m_Turn;

	GameRenderer*			m_GameRenderer;
	GameInterface*			m_GameInterface;
	Player*					m_Player1;
	Player*					m_Player2;
};
