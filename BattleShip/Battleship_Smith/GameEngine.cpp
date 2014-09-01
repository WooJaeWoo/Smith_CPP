#include "stdafx.h"
#include "GameEngine.h"
#include "GameManager.h"
#include "Map.h"
#include "Player.h"

GameEngine::GameEngine()
{
	m_GameManager = new GameManager();
	m_player1 = new Player();
	m_player2 = new Player();
	m_NumShip.push_back(1);
	m_NumShip.push_back(1);
	m_NumShip.push_back(1);
	m_NumShip.push_back(2);
}

GameEngine::~GameEngine()
{	
	delete m_GameManager;
	delete m_player1;
	delete m_player2;
}

void GameEngine::GameRun()
{
	m_GameManager->SetWindowTitle();
	m_GameManager->RenderTitle();
	
	//SELECT PLAYER MODE
	m_GameManager->PlayerSettingPage();
	m_PlayerType = m_GameManager->GetPlayerType();

	//INITIALIZE THE NUMBER OF SHIPS
	m_GameManager->SetNumShip(m_NumShip);

	//GAME SETTING (MAP SIZE, SHIPS)
	m_GameManager->GameSettingPage();

	//MAKE MAPS
	m_player1->MakeMaps(m_GameManager->GetMapSize());
	m_player2->MakeMaps(m_GameManager->GetMapSize());
	
	//MAP MACHING
	m_p1_MyMap = m_player1->GetMyMap();
	m_p1_EnemyMap = m_player1->GetEnemyMap();
	m_p2_MyMap = m_player2->GetMyMap();
	m_p2_EnemyMap = m_player2->GetEnemyMap();

	//MAKE SHIPS
	m_player1->SetNumShip(m_GameManager->GetNumShip());
	m_player2->SetNumShip(m_GameManager->GetNumShip());
	SetNumShip(m_GameManager->GetNumShip());
	m_player1->MakeShips();
	m_player2->MakeShips();

	m_GameManager->ShipSettingPage(*m_p1_MyMap);

	for (int i = 0; i < m_NumShip.size(); i++)
	{
		for (int j = m_NumShip[i]; j != 0; j--)
		{
			m_GameManager->SetUpShipOnMap((ShipType)i, *m_p1_MyMap);
		}
	}

	//Gamestart or reset

	m_GameManager->GamePlayPage(*m_p1_EnemyMap, *m_p1_MyMap); //실제로는 while문 안에서 번갈아서 진행해야 함
	m_GameManager->AttakInterface();
	
	m_GameManager->PrintTurn();



	//m_GameManager->SetUpShipOnMap(AIRCRAFT, *m_p1_MyMap);
	//system("cls");
	//switch (m_PlayerType)
	//{
	//	case NORMAL:
	//		m_GameManager->ShipSettingPage(*m_p2_MyMap);
	//		break;
	//	case AI:
	//		m_player2->LocateShips();
	//		break;
	//	case NETWORK:
	//		break;
	//}
}