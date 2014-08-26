#include "stdafx.h"
#include "GameManager.h"
#include "GameRender.h"
#include "Map.h"
#include "Player.h"

GameManager::GameManager()
{
	m_GameRender = new GameRender();
	m_player1 = new Player();
	m_player2 = new Player();
	m_NumShip.push_back(1);
	m_NumShip.push_back(1);
	m_NumShip.push_back(1);
	m_NumShip.push_back(2);
}


GameManager::~GameManager()
{	
	delete m_GameRender;
	delete m_player1;
	delete m_player2;
}

void GameManager::GameRun()
{
	m_GameRender->SetWindowTitle();
	m_GameRender->RenderTitle();
	
	//SELECT PLAYER MODE
	m_GameRender->RenderPlayerSettingPage();
	m_PlayerType = m_GameRender->GetPlayerType();

	//INITIALIZE THE NUMBER OF SHIPS
	m_GameRender->SetNumShip(m_NumShip);

	//GAME SETTING (MAP SIZE, SHIPS)
	m_GameRender->RenderGameSettingPage(*m_p1_MyMap);
	
	//MAKE SHIPS
	m_player1->SetNumShip(m_GameRender->GetNumShip());
	m_player2->SetNumShip(m_GameRender->GetNumShip());
	m_player1->MakeShips();
	m_player2->MakeShips();


	//SET THE MAP SIZE
	m_p1_EnemyMap->SetMaxSizeofMap(m_p1_MyMap->GetMaxSizeofMap());
	m_p2_MyMap->SetMaxSizeofMap(m_p1_MyMap->GetMaxSizeofMap());
	m_p2_EnemyMap->SetMaxSizeofMap(m_p1_MyMap->GetMaxSizeofMap());

	//MAP MAKING & MACHING
	m_player1->MakeMaps();
	m_player2->MakeMaps();
	m_p1_MyMap = m_player1->GetMyMap();
	m_p1_EnemyMap = m_player1->GetEnemyMap();
	m_p2_MyMap = m_player2->GetMyMap();
	m_p2_EnemyMap = m_player2->GetEnemyMap();
	
	m_GameRender->RenderShipSettingPage(*m_p1_MyMap);
	m_GameRender->SetUpShipOnMap(AIRCRAFT, *m_p1_MyMap);
	switch (m_PlayerType)
	{
	case NORMAL:
		break;
	case AI:
		m_player2->LocateShips();
		break;
	case NETWORK:
		break;
	}
}