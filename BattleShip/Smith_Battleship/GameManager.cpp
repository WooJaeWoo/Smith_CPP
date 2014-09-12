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
	m_GameType = PVA;
	m_MapSize = 8;
	m_NumShip.clear();
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
			m_GameType = m_GameInterface->GetGameType();
			
			if (m_GameType == PVA)
				m_GameStatus = SELECT_MAP_SHIP;
			else if (m_GameType == PVN)
				m_GameStatus = GAMEPLAY;
			else if (m_GameType == PVP) //SEALED!!!
				exit(0);
			break;
		case SELECT_MAP_SHIP:
			m_MapSize = m_GameInterface->GetMapSize();
			m_GameRenderer->SetSizeOfMap(m_MapSize);
			m_NumShip = m_GameInterface->GetNumShip();
			MakePlayers();
			m_GameStatus = SET_SHIP;
			break;
		case SET_SHIP:
			ReadyToFight(m_Player1);
			ReadyToFight(m_Player2);
			if (m_GameInterface->GameStartOrReset())
				m_GameStatus = GAMEPLAY;
			else
			{
				m_Player1->InitializeMyStatus();
				m_Player2->InitializeMyStatus();
				m_GameStatus = SET_SHIP;
			}
			break;
		case GAMEPLAY:
		{
			while (true)
			{
				m_Player1->RenderUpdateMapStatus((m_MapSize + 3) * 4 + 30, 11);
				m_GameInterface->AttackInterface();
				m_GameRenderer->PrintResult(HIT);
				m_GameRenderer->PrintTurn(m_Turn++, m_MapSize);	
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
		}
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
	if (m_GameType == PVP)
	{
		m_Player1->SetPlayerType(PLAYER);
		m_Player2->SetPlayerType(PLAYER);
	}
	else if (m_GameType == PVA)
	{
		m_Player1->SetPlayerType(PLAYER);
		m_Player2->SetPlayerType(AI);
	}
	else if (m_GameType == PVN)
	{
		m_Player1->SetPlayerType(AI);
		m_Player2->SetPlayerType(NETWORK);
	}
	m_Player1->MakeMaps(m_MapSize);
	m_Player2->MakeMaps(m_MapSize);
	m_Player1->SetNumShip(m_NumShip);
	m_Player2->SetNumShip(m_NumShip);
	m_Player1->MakeShips();
	m_Player2->MakeShips();
}

void GameManager::ReadyToFight(Player* player)
{
	m_NumShip = m_GameInterface->GetNumShip();
	player->SetNumShip(m_NumShip);
	if (player->GetPlayerType() == PLAYER)
	{
		player->RenderUpdateMapStatus(9, 11);
		player->RenderRemain();
	}
	int shipType = 0;
	for (int i = 0;; ++i)
	{
		if (shipType == 4)
			break;
		if (m_NumShip[shipType] == 0)
		{
			shipType++;
		}
		else
		{
			Position positionToSend;
			while (true)
			{
				if (player->GetPlayerType() == PLAYER && m_GameInterface->GetSetOption() == true)
					positionToSend = m_GameInterface->PositionToSetShip((ShipType)shipType);
				else
					positionToSend = player->RandomSetShip((ShipType)shipType);
				if (player->IsValidSet(positionToSend, (ShipType)shipType))
				{
					player->SetShip(positionToSend, (ShipType)shipType);
					m_NumShip[shipType]--;
					player->SetNumShip(m_NumShip);
					if (player->GetPlayerType() == PLAYER) player->RenderRemain();
					//¹è ÁÂÇ¥ Çª½Ã
					break;
				}
				if (player->GetPlayerType() == PLAYER) player->RenderUpdateMapStatus(9, 11);
			}
		}
		if (player->GetPlayerType() == PLAYER) player->RenderUpdateMapStatus(9, 11);
	}
}
