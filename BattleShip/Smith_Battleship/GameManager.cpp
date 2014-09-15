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
	m_GameStatus = GAMESTART;
}

GameManager::~GameManager()
{
	delete m_GameInterface;
	delete m_Player1;
	delete m_Player2;
}

void GameManager::InitializeGame()
{
	m_GameStatus = GAMESTART;
	m_GameType = PVA;
	m_MapSize = 8;
	m_Turn = 0;
	m_GameRenderer->InitializeRenderer();
	m_GameInterface->InitializeInterface();
	m_NumShip.clear();
	m_NumShip = m_GameInterface->GetNumShip();
}
void GameManager::ResetGame()
{
	m_GameStatus = SET_SHIP;
	m_NumShip = m_GameInterface->GetNumShip();
	m_Player1->SetNumShip(m_NumShip);
	m_Player2->SetNumShip(m_NumShip); 
	m_Turn = 0;
	m_GameRenderer->ResetRenderer();
	m_GameInterface->ResetInterface();
	m_Player1->ResetPlayer();
	m_Player2->ResetPlayer();
}

void GameManager::DefaultGame()
{
	m_GameType = AVN;
	m_GameInterface->DefaultInterface();
	m_NumShip = m_GameInterface->GetNumShip();
	m_Player1->SetNumShip(m_NumShip);
	m_Player2->SetNumShip(m_NumShip);
	m_GameRenderer->DefaultRenderer();
	m_Player1->DefaultPlayer();
	m_Player2->DefaultPlayer();
	m_Turn = 1;
	m_MapSize = 8;
}

void GameManager::GameRun()
{
	int	winner;
	int lastMenu = -1;
	bool okToExit = false;
	m_GameRenderer->SetWindowTitle();
	while (true)
	{
		//DataControl
		switch (m_GameStatus)
		{
		case GAMESTART: //Dummy Case
			m_GameStatus = TITLE;
			break;
		case TITLE:
			InitializeGame();
			m_GameStatus = SELECT_PLAYER;
			break;
		case SELECT_PLAYER:
			m_GameType = m_GameInterface->GetGameType();
			SetPlayerType();
			if (m_GameType == PVP || m_GameType == PVA)
				m_GameStatus = SELECT_MAP_SHIP;
			else if (m_GameType == AVN)
			{
				DefaultGame();
				AVNSetShip();
				m_GameStatus = GAMEPLAY;
			}
			break;
		case SELECT_MAP_SHIP:
			m_MapSize = m_GameInterface->GetMapSize();
			m_GameRenderer->SetSizeOfMap(m_MapSize);
			m_NumShip = m_GameInterface->GetNumShip();
			MakeMapAndShip();
			m_GameStatus = SET_SHIP;
			break;
		case SET_SHIP:
		{
			if (m_GameType == PVP)
			{
				PVPSetShip();
			}
			else if (m_GameType == PVA)
			{
				PVASetShip();
			}
			m_GameStatus = GAMEPLAY;
			break;
		}
		case GAMEPLAY: 
		{
			if (m_GameType == PVP)
			{
				winner = PVPGameFlow();
				m_GameStatus = WIN;
			}
			else if (m_GameType == PVA)
			{
				winner = PVAGameFlow();
				if (winner == 0)
					m_GameStatus = WIN;
				else
					m_GameStatus = LOSE;
			}
			else if (m_GameType == AVN)
			{
				//m_Winner = AVNGameFlow();
			}
			lastMenu = -1;
			break;
		}
		case WIN:
			lastMenu = m_GameInterface->GetLastMenu();
			okToExit = LastMenuDecision(lastMenu);
			break;
		case LOSE:
			lastMenu = m_GameInterface->GetLastMenu();
			okToExit = LastMenuDecision(lastMenu);
			break;
		}
		if (lastMenu != -1)
		{
			if (okToExit) break;
		}
		m_GameRenderer->RenderPages(m_GameStatus, m_GameType);
		if (m_GameStatus == WIN || m_GameStatus == LOSE)
			WriteGameResult(winner);
		m_GameInterface->AttachInterface(m_GameStatus);
	}
}

bool GameManager::AttackFlow(Player* player1, Player* player2)
{
	bool isGameOver = false;
	Coordinate shot;
	HitResult shotResult = WRONG;
	if (player1->GetPlayerType() == PLAYER)
	{
		do
		{
			if (player1->GetPlayerID() == 0)
				shot = m_GameInterface->AttackInterface(9, 11);
			else
				shot = m_GameInterface->AttackInterface((m_MapSize + 3) * 4 + 30, 11);
			shotResult = player2->SendResult(shot);
		} while (shotResult == WRONG);
		m_GameRenderer->PrintResult(shotResult);
	}
	else if (player1->GetPlayerType() == AI)
	{
		do
		{
			shot = player1->RandomAttack();
			shotResult = player2->SendResult(shot);
		} while (shotResult == WRONG);
	}
	player1->MarkOnEnemyMap(shot, shotResult);
	if (player2->GameOverCheck(shotResult))
	{
		isGameOver = true;
	}
	return isGameOver;
}

int GameManager::PVPGameFlow()
{
	bool isWin = false;
	while (true)
	{
		m_GameRenderer->PrintTurn(++m_Turn, m_MapSize);
		isWin = AttackFlow(m_Player1, m_Player2);
		m_Player1->RenderUpdateEnemyMapStatus(9, 11);
		if (isWin == true)
			return m_Player1->GetPlayerID();
		isWin = AttackFlow(m_Player2, m_Player1);
		m_Player2->RenderUpdateEnemyMapStatus((m_MapSize + 3) * 4 + 30, 11);
		if (isWin == true)
			return m_Player2->GetPlayerID();
	}
}

int GameManager::PVAGameFlow()
{
	bool isWin = false;
	while (true)
	{
		m_GameRenderer->PrintTurn(++m_Turn, m_MapSize);
		m_Player1->RenderUpdateMyMapStatus((m_MapSize + 3) * 4 + 30, 11);
		isWin = AttackFlow(m_Player1, m_Player2);
		m_Player1->RenderUpdateEnemyMapStatus(9, 11);
		if (isWin == true)
			return m_Player1->GetPlayerID();
		isWin = AttackFlow(m_Player2, m_Player1);
		m_Player1->RenderUpdateMyMapStatus((m_MapSize + 3) * 4 + 30, 11);
		if (isWin == true)
			return m_Player2->GetPlayerID();
	}
}

void GameManager::SetPlayerType()
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
	else if (m_GameType == AVN)
	{
		m_Player1->SetPlayerType(AI);
		m_Player2->SetPlayerType(NETWORK);
	}
}

void GameManager::MakeMapAndShip()
{
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
		player->RenderUpdateMyMapStatus(9, 11);
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
			Position positionToSet;
			while (true)
			{
				if (player->GetPlayerType() == PLAYER && m_GameInterface->GetSetOption() == true)
					positionToSet = m_GameInterface->PositionToSetShip((ShipType)shipType);
				else
					positionToSet = player->RandomSetShip((ShipType)shipType);
				if (player->IsValidSet(positionToSet, (ShipType)shipType))
				{
					player->SetShip(positionToSet, (ShipType)shipType);
					m_NumShip[shipType]--;
					player->SetNumShip(m_NumShip);
					if (player->GetPlayerType() == PLAYER) player->RenderRemain();
					break;
				}
				if (player->GetPlayerType() == PLAYER) player->RenderUpdateMyMapStatus(9, 11);
			}
		}
		if (player->GetPlayerType() == PLAYER) player->RenderUpdateMyMapStatus(9, 11);
	}
	player->SetShipCoords();
	m_NumShip = m_GameInterface->GetNumShip();
	player->SetNumShip(m_NumShip);
}   

void GameManager::WriteGameResult(int who)
{
	SetCursorAndColor(24, 8, WHITE, BLACK);
	if (m_GameType == PVA && who == 1)
		printf_s("    AI WIN    ", who + 1);
	else
		printf_s(" PLAYER %d WIN", who + 1);
	SetCursorPosition(24, 10);
	printf_s("    %d Turn    ", m_Turn);

}

void GameManager::PVPSetShip()
{
	bool okToStart = false;
	SetCursorAndColor(0, 7, BLACK, WHITE);
	printf_s(" Setting - Player 1 ");
	do
	{
		m_Player1->ResetPlayer();
		ReadyToFight(m_Player1);
		okToStart = m_GameInterface->GameStartOrReset();
		if (okToStart)
			break;
	} while (!okToStart);
	SetCursorAndColor(0, 7, BLACK, WHITE);
	printf_s(" Setting - Player 2 ");
	do
	{
		m_Player2->ResetPlayer();
		ReadyToFight(m_Player2);
		okToStart = m_GameInterface->GameStartOrReset();
		if (okToStart)
			break;
	} while (!okToStart);
}

void GameManager::PVASetShip()
{
	bool okToStart = false;
	do 
	{
		m_Player1->ResetPlayer();
		m_Player2->ResetPlayer();
		ReadyToFight(m_Player1);
		ReadyToFight(m_Player2);
		okToStart = m_GameInterface->GameStartOrReset();
		if (okToStart)
			break;
	} while (!okToStart);
}

void GameManager::AVNSetShip()
{
	ReadyToFight(m_Player1);
	ReadyToFight(m_Player2);
}

bool GameManager::LastMenuDecision(int lastMenu)
{
	if (lastMenu == 0)
	{
		InitializeGame();
		m_Player1->InitializePlayer();
		m_Player2->InitializePlayer();
		return false;
	}
	else if (lastMenu == 1)
	{
		ResetGame();
		return false;
	}
	else
	{
		return true;
	}
}
