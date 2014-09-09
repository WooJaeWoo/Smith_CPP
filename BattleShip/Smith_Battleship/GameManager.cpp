#include "stdafx.h"
#include "GameManager.h"
#include "GameRenderer.h"
#include "GameInterface.h"
#include "Player.h"
#include "Map.h"

GameManager::GameManager()
{
	m_GameInterface = new GameInterface();
	m_GameRenderer = m_GameInterface->GetGameRenderer();
	m_Player1 = new Player();
	m_Player2 = new Player();
	m_GameStatus = TITLE;
}


GameManager::~GameManager()
{
	delete m_GameInterface;
	delete m_Player1;
	delete m_Player2;
}


void GameManager::GameInitialize()
{
	m_PlayerType = NONE;
	m_MapSize = 8;
	m_NumShip.clear();
	m_Positions.clear();
	m_Turn = 1;
	m_GameRenderer->InitializeRenderer();
	m_GameInterface->InitializeInterface();
}

void GameManager::GameRun()
{
	m_GameRenderer->SetWindowTitle();
	while (true)
	{
		m_GameRenderer->RenderPages(m_GameStatus);
		m_GameInterface->AttachInterface(m_GameStatus);
		//DataControl
		switch (m_GameStatus)
		{
		case TITLE:
			GameInitialize();
			m_GameStatus = SELECT_PLAYER;
			break;
		case SELECT_PLAYER:
			m_PlayerType = m_GameInterface->GetPlayerType();
			if (m_PlayerType == NETWORK)
				m_GameStatus = GAMEPLAY;
			else
				m_GameStatus = SELECT_MAP_SHIP;
			break;
		case SELECT_MAP_SHIP:
			m_MapSize = m_GameInterface->GetMapSize();
			m_GameRenderer->SetSizeOfMap(m_MapSize);
			m_NumShip = m_GameInterface->GetNumShip();
			MakePlayers();
			m_GameStatus = SET_SHIP;
			break;
		case SET_SHIP:
			m_Positions = m_GameInterface->GetShipPositions();
			m_GameStatus = GAMEPLAY;
			break;
		case GAMEPLAY:
			
			while (true)
			{
				/*Get HitResult and put it as argument
				m_GameRenderer->PrintResult()*/
				m_GameRenderer->PrintTurn(m_Turn++);
			
			}
			
			/*if ()
			{
				m_GameStatus = WIN;
			}
			else
			{
				m_GameStatus = LOSE;
			}*/
			break;
		case WIN:
			m_GameStatus = LOSE;
			break;
		case LOSE:
			break;
		}
		//m_GameStatus = (GameStatus)(((int)m_GameStatus + 1) % 7);
	}
}

void GameManager::MakePlayers()
{
	m_Player1->SetPlayerType(m_PlayerType);
	m_Player2->SetPlayerType(m_PlayerType);
	m_Player1->MakeMaps(m_MapSize);
	m_Player2->MakeMaps(m_MapSize);
	m_Player1->SetNumShip(m_NumShip);
	m_Player2->SetNumShip(m_NumShip);
	m_Player1->MakeShips();
	m_Player2->MakeShips();
	m_P1_MyMap = m_Player1->GetMyMap();
	m_P1_EnemyMap = m_Player1->GetEnemyMap();
	m_P2_MyMap = m_Player2->GetMyMap();
	m_P2_EnemyMap = m_Player2->GetEnemyMap();
}
