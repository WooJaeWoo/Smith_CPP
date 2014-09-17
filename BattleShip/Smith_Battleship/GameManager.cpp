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

// 게임을 처음부터 완전 초기화 (Map, Ship은 Delete)
void GameManager::InitializeGame()
{
	m_GameStatus = GAMESTART;
	m_GameType = AI_PLAY;
	m_MapSize = 8;
	m_Turn = 0;
	m_GameRenderer->InitializeRenderer();
	m_GameInterface->InitializeInterface();
	m_NumShip.clear();
	m_NumShip = m_GameInterface->GetNumShip();
	m_ShipPositions.clear();
}

// 동일한 세팅으로 게임 오브젝트 초기화 (New Delete 없음)
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
	m_ShipPositions.clear();
}

void GameManager::DefaultGameSetting()
{
	m_GameInterface->DefaultInterface();
	m_NumShip = m_GameInterface->GetNumShip();
	m_Player1->SetNumShip(m_NumShip);
	m_Player2->SetNumShip(m_NumShip);
	m_GameRenderer->DefaultRenderer();
	m_Player1->DefaultPlayer();
	m_Player2->DefaultPlayer();
	m_Turn = 1;
	m_MapSize = 8;
	m_ShipPositions.clear();
}

void GameManager::GameRun()
{
	int	winner = -1;
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
			if (m_GameType == PVP_PLAY || m_GameType == AI_PLAY)
				m_GameStatus = SELECT_MAP_SHIP;
			else if (m_GameType == NET_PLAY)
			{
				DefaultGameSetting();
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
			if (m_GameType == PVP_PLAY)
			{
				PVP_PlaySetShip();
			}
			else if (m_GameType == AI_PLAY)
			{
				AI_PlaySetShip();
			}
			m_GameStatus = GAMEPLAY;
			break;
		}
		case GAMEPLAY: 
		{
			if (m_GameType == PVP_PLAY)
			{
				winner = PVP_PlayGameFlow();
				m_GameStatus = WIN;
			}
			else if (m_GameType == AI_PLAY)
			{
				winner = AI_PlayGameFlow();
				if (winner == 0)
					m_GameStatus = WIN;
				else
					m_GameStatus = LOSE;
			}
			else if (m_GameType == NET_PLAY)
			{
				NET_PlayGameFlow();
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

bool GameManager::AttackFlow(Player* attacker, Player* defender)
{
	bool isGameOver = false;
	Coordinate shot;
	HitResult shotResult = WRONG;
	if (attacker->GetPlayerType() == PLAYER)
	{
		do
		{
			if (attacker->GetPlayerID() == 0)
				shot = m_GameInterface->AttackInterface(FIRST_MAP_GOTOX, FIRST_MAP_GOTOY);
			else
				shot = m_GameInterface->AttackInterface((m_MapSize + 3) * 4 + 30, FIRST_MAP_GOTOY);
			shotResult = defender->SendResult(shot);
		} while (shotResult == WRONG);
		m_GameRenderer->PrintResult(shotResult);
	}
	else if (attacker->GetPlayerType() == AI)
	{
		do
		{
			shot = attacker->RandomAttack();
			shotResult = defender->SendResult(shot);
		} while (shotResult == WRONG);
	}
	attacker->MarkOnEnemyMap(shot, shotResult);
	if (defender->GameOverCheck(shotResult))
	{
		isGameOver = true;
	}
	return isGameOver;
}

int GameManager::PVP_PlayGameFlow()
{
	bool isWin = false;
	while (true)
	{
		m_GameRenderer->PrintTurn(++m_Turn, m_MapSize);
		isWin = AttackFlow(m_Player1, m_Player2);
		m_Player1->RenderUpdateEnemyMapStatus(FIRST_MAP_GOTOX, FIRST_MAP_GOTOY);
		if (isWin == true)
			return m_Player1->GetPlayerID();
		isWin = AttackFlow(m_Player2, m_Player1);
		m_Player2->RenderUpdateEnemyMapStatus((m_MapSize + 3) * 4 + 30, FIRST_MAP_GOTOY);
		if (isWin == true)
			return m_Player2->GetPlayerID();
	}
}

int GameManager::AI_PlayGameFlow()
{
	bool isWin = false;
	while (true)
	{
		m_GameRenderer->PrintTurn(++m_Turn, m_MapSize);
		m_Player1->RenderUpdateMyMapStatus((m_MapSize + 3) * 4 + 30, FIRST_MAP_GOTOY);
		isWin = AttackFlow(m_Player1, m_Player2);
		m_Player1->RenderUpdateEnemyMapStatus(FIRST_MAP_GOTOX, FIRST_MAP_GOTOY);
		if (isWin == true)
			return m_Player1->GetPlayerID();
		isWin = AttackFlow(m_Player2, m_Player1);
		m_Player1->RenderUpdateMyMapStatus((m_MapSize + 3) * 4 + 30, FIRST_MAP_GOTOY);
		if (isWin == true)
			return m_Player2->GetPlayerID();
	}
}

void GameManager::NET_PlayGameFlow()
{
	Network network;
	PacketType type;
	ErrorType error;

	try
	{
		Network::Initialize();
	}
	catch (Network::Exception)
	{
		puts("초기화 도중 문제가 발생했습니다.");
		return;
	}

	try
	{
		network.Connect("10.73.42.117", 9001);
	}
	catch (Network::Exception ex)
	{
		switch (ex)
		{
		case Network::NETWORK_ERROR:
			puts("서버와 연결에 실패했습니다.");
			break;
		case Network::PARAMETER_ERROR:
			puts("함수의 인수가 잘못되었습니다.");
			break;
		}
		return;
	}
	puts("접속 성공!");

	try
	{
		const wchar_t name[MAX_NAME_LEN] = L"SMITHOO";
		const int studentID = 141055;

		error = network.SubmitName(name, studentID);
		if (error == ET_DUPLICATED_NAME)
		{
			puts("이미 존재하는 이름입니다.");
			return;
		}

		Network::GameStartData gameStartData;
		puts("게임 시작 대기중");
		network.WaitForStart(&gameStartData);
		wprintf_s(L"매칭되었습니다. 상대방 이름: %s, 학번: %d\n", gameStartData.oppositionName, gameStartData.oppositionStudentID);

		bool allOver = false;
		while (!allOver) //10판 종료
		{
			ShipData shipData;
			Network::Initialize();


			char mapData[MAP_SIZE];
			
			while (true)
			{
				ReadyToFight(m_Player1);
				ReadyToFight(m_Player2);
				m_GameRenderer->RenderPages(GAMEPLAY, NET_PLAY);
				for (int i = 0; i < DEFAULT_SHIP_COUNT; ++i)
				{
					Position netPosition;
					if (i != 4)
						netPosition = ConvertPosionForNET((ShipType)i, m_ShipPositions[i]);
					else if (i == 4)
						netPosition = ConvertPosionForNET((ShipType)(i - 1), m_ShipPositions[i]);
					shipData.SetShip((ShipData::ShipType)(i + 1), Coord(netPosition.m_X, netPosition.m_Y), netPosition.m_direction == 0 ? ShipData::DIR_VERTICAL : ShipData::DIR_HORIZONTAL);
				}
				shipData.ToMapData(mapData);
				error = network.SubmitMap(mapData);
				if (error == ET_INVALID_MAP)
					puts("유효하지 않은 맵 데이터입니다.");
				else
					break;
			}

			bool gameOver = false;

			while (!gameOver)
			{
				error = network.GetPacketType(&type);

				switch (type)
				{
				case PKT_SC_ERROR:
					if (error == ET_OPPOSITION_DISCONNECTED)
						puts("상대방의 접속이 끊어졌습니다.");
					else
						puts("알 수 없는 에러입니다.");
					return;

				case PKT_SC_MY_TURN: /* 공격 위치 전송 x, y는 0~7 사이의 정수이다.*/
				{
					Coordinate netShot;
					bool isAttacked;
					while (true)
					{
						do
						{
							netShot = m_Player1->RandomAttack(); //Make AI Attack T-T
							//netShot = m_GameInterface->AttackInterface(FIRST_MAP_GOTOX, FIRST_MAP_GOTOY); //Manual Mode
							isAttacked = m_Player2->CheckAttacked(netShot);
						} while (isAttacked);
						Coord myShot(netShot.m_X, netShot.m_Y);
						error = network.SubmitAttack(myShot);
						if (error == ET_INVALID_ATTACK)
							printf_s("유효하지 않은 공격");
						else
							break;
					}
					break;
				}

				case PKT_SC_ATTACK_RESULT:
				{
					Network::AttackResultData attackResult = network.GetAttackResult();
					Coordinate shot;
					shot.m_X = attackResult.pos.mX;
					shot.m_Y = attackResult.pos.mY;
					HitResult shotResult = (HitResult)attackResult.attackResult;
					if (attackResult.isMine) //내 에너미 맵에 내가 공격한 결과를 반영 마크
					{
						m_GameRenderer->PrintResult(shotResult);
						m_GameRenderer->PrintTurn(++m_Turn, DEFAULT_MAP_SIZE);
						m_Player1->MarkOnEnemyMap(shot, shotResult);
						m_Player2->MarkOnMyMap(shot, shotResult);
						m_Player1->RenderUpdateEnemyMapStatus(FIRST_MAP_GOTOX, FIRST_MAP_GOTOY);
					}
					else //내가 어택당하는 함수
					{
						m_Player1->MarkOnMyMap(shot, shotResult);
						m_Player1->RenderUpdateMyMapStatus((m_MapSize + 3) * 4 + 30, FIRST_MAP_GOTOY);
					}
					break;
				}

				case PKT_SC_GAME_OVER:
				{
					Network::GameResultData gameResult = network.GetGameResult();
					ResetGame();
					if (gameResult.isWinner)
						puts("승리!!!");
					else
						puts("패배...");
					printf_s("턴 수: %d\n", gameResult.turns);
					gameOver = true;
					break;
				}
				default:
					throw Network::UNEXPECTED_PACKET;
					break;
				}
			}
			network.GetPacketType(&type);


			if (type == PKT_SC_NEXT_GAME)
			{
				puts("다음 게임을 준비해주세요.");
			}
			else if (type == PKT_SC_ALL_OVER)
			{
				Network::FinalResultData finalResult = network.GetFinalResult();
				allOver = true;
			}
			else
				throw Network::UNEXPECTED_PACKET;
		}
	}
	catch (Network::Exception ex)
	{
		switch (ex)
		{
		case Network::NETWORK_ERROR:
			puts("네트워크에 문제가 발생했습니다.");
			break;
		case Network::SERVER_CLOSED:
			puts("서버와의 연결이 끊어졌습니다.");
			break;
		case Network::PARAMETER_ERROR:
			puts("함수의 인수가 잘못되었습니다.");
			break;
		case Network::UNEXPECTED_PACKET:
			puts("서버에서 잘못된 정보가 전송되었습니다.");
			break;
		default:
			break;
		}
	}
	network.Disconnect();
	m_GameStatus = WIN;
}

Position GameManager::ConvertPosionForNET(ShipType shipType, Position position)
{
	Position convertedPos;
	switch (position.m_direction)
	{
	case DOWN:
		convertedPos = position;
		break;
	case UP:
		convertedPos.m_X = position.m_X;
		convertedPos.m_Y = position.m_Y - (GetMaxHP(shipType) - 1);
		convertedPos.m_direction = DOWN;
		break;
	case RIGHT:
		convertedPos = position;
		break;
	case LEFT:
		convertedPos.m_X = position.m_X - (GetMaxHP(shipType) - 1);
		convertedPos.m_Y = position.m_Y;
		convertedPos.m_direction = RIGHT;
		break;
	}
	return convertedPos;
}

void GameManager::SetPlayerType()
{
	if (m_GameType == PVP_PLAY)
	{
		m_Player1->SetPlayerType(PLAYER);
		m_Player2->SetPlayerType(PLAYER);
	}
	else if (m_GameType == AI_PLAY)
	{
		m_Player1->SetPlayerType(PLAYER);
		m_Player2->SetPlayerType(AI);
	}
	else if (m_GameType == NET_PLAY)
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
		player->RenderUpdateMyMapStatus(FIRST_MAP_GOTOX, FIRST_MAP_GOTOY);
		player->RenderRemain();
	}
	if (player->GetPlayerType() != NETWORK)
	{
		int shipType = 0;
		for (int i = 0;; ++i)
		{
			if (shipType == 4)
				break;
			if (m_NumShip[shipType] == 0)
				shipType++;
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
						m_ShipPositions.push_back(positionToSet);
						player->SetNumShip(m_NumShip);
						if (player->GetPlayerType() == PLAYER) player->RenderRemain();
						break;
					}
					if (player->GetPlayerType() == PLAYER) player->RenderUpdateMyMapStatus(FIRST_MAP_GOTOX, FIRST_MAP_GOTOY);
				}
			}
			if (player->GetPlayerType() == PLAYER) player->RenderUpdateMyMapStatus(FIRST_MAP_GOTOX, FIRST_MAP_GOTOY);
		}
		player->SetShipCoords();
		m_NumShip = m_GameInterface->GetNumShip();
		player->SetNumShip(m_NumShip);
	}
}   

void GameManager::WriteGameResult(int who)
{
	if (who < 0)
		return;
	if (m_GameType == PVP_PLAY || m_GameType == AI_PLAY)
	{
		SetCursorAndColor(24, 8, WHITE, BLACK);
		if (m_GameType == AI_PLAY && who == 1)
			printf_s("    AI WIN    ", who + 1);
		else
			printf_s(" PLAYER %d WIN", who + 1);
		SetCursorPosition(24, 10);
		printf_s("    %d Turn    ", m_Turn);
	}
}

void GameManager::PVP_PlaySetShip()
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

void GameManager::AI_PlaySetShip()
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

