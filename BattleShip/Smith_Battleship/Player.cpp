#include "stdafx.h"
#include "Player.h"
#include "Map.h"
#include "Ship.h"
#include "Aircraft.h"
#include "Battleship.h"
#include "Cruiser.h"
#include "Destroyer.h"

int Player::m_IDSeed = 0;
#define DEFAULT_MAP_SIZE 8

Player::Player()
{
	m_PlayerID = (m_IDSeed++) % 2;
}

Player::~Player()
{
	ClearPlayer();
}

void Player::InitializePlayer()
{
	ClearPlayer();
}

void Player::ClearPlayer()
{
	delete m_MyMap;
	m_MyMap = nullptr;
	delete m_EnemyMap;
	m_EnemyMap = nullptr;
	for (auto ship : m_ShipList)
	{
		delete ship;
		ship = nullptr;
	}
	m_ShipList.clear();
	m_NumShip.clear();
	m_ShipList.reserve(0);
	m_ShipPositions.clear();
	m_AIMemHitResult = MISS;
}

void Player::ResetPlayer()
{
	m_MyMap->ResetMap();
	m_EnemyMap->ResetMap();
	for (std::vector<Ship*>::iterator it = m_ShipList.begin(); it != m_ShipList.end(); ++it)
	{
		(*it)->ResetShip();
	}
	m_ShipPositions.clear();
	m_AIMemHitResult = MISS;
}

void Player::DefaultPlayer()
{
	MakeMaps(DEFAULT_MAP_SIZE);
	m_MyMap->SetSizeOfMap(DEFAULT_MAP_SIZE);
	m_EnemyMap->SetSizeOfMap(DEFAULT_MAP_SIZE);
	m_ShipList.clear();
	MakeShips();
	m_AIMemHitResult = MISS;
}

void Player::MakeMaps(int mapSize)
{
	m_MyMap = new Map(mapSize);
	m_EnemyMap = new Map(mapSize);
}

void Player::MakeShips()
{
	m_ShipList.clear();
	for (int i = 0; i < m_NumShip[0]; i++)
	{
		m_ShipList.push_back(new Aircraft());
	}
	for (int i = 0; i < m_NumShip[1]; i++)
	{
		m_ShipList.push_back(new Battleship());
	}
	for (int i = 0; i < m_NumShip[2]; i++)
	{
		m_ShipList.push_back(new Cruiser());
	}
	for (int i = 0; i < m_NumShip[3]; i++)
	{
		m_ShipList.push_back(new Destroyer());
	}
}

void Player::SetShip(Position position, ShipType shipType)
{
	m_MyMap->SetMapStatus(position, (MapStatus)((int)shipType + 1), shipType);
	m_ShipPositions.push_back(position);
}

void Player::RenderUpdateMyMapStatus(int gotoX, int gotoY)
{
	m_MyMap->RenderMapStatus(gotoX, gotoY);
}

void Player::RenderUpdateEnemyMapStatus(int gotoX, int gotoY)
{
	m_EnemyMap->RenderMapStatus(gotoX, gotoY);
}

Position Player::RandomSetShip(ShipType shipType)
{
	Position position;
	position.m_X = rand() % m_MyMap->GetMapSize();
	position.m_Y = rand() % m_MyMap->GetMapSize();
	position.m_direction = (Direction)(rand() % 4);
	return position;
}

HitResult Player::SendResult(Coordinate shot)
{
	HitResult hitResult;
	if (m_MyMap->GetMapStatus(shot.m_X, shot.m_Y) == ATTACKED_SHIP || m_MyMap->GetMapStatus(shot.m_X, shot.m_Y) == ATTACKED_MISS)
		return WRONG;
	for (auto ship : m_ShipList)
	{
		hitResult = ship->HitCheck(shot);
		if (hitResult != MISS)
		{
			m_MyMap->SetMapStatus(shot, ATTACKED_SHIP);
			return hitResult;
		}
	}
	m_MyMap->SetMapStatus(shot, ATTACKED_MISS);
	return MISS;
}

bool Player::CheckAttacked(Coordinate shot)
{
	MapStatus mapStatus = m_MyMap->GetMapStatus(shot.m_X, shot.m_Y);
	if (mapStatus == NOTHING && mapStatus != ATTACKED_SHIP && mapStatus != ATTACKED_MISS)
	{
		return false;
	}
	else
		return true;
}

bool Player::IsValidSet(Position position, ShipType shipType)
{
	int maxHP = GetMaxHP(shipType);
	for (int i = 0; i < maxHP; ++i)
	{
		if (position.m_X < 0 || position.m_X > m_MyMap->GetMapSize() - 1 || position.m_Y < 0 || position.m_Y > m_MyMap->GetMapSize() - 1)
		{
			return false;
		}
		if (m_MyMap->GetMapStatus(position.m_X, position.m_Y) != NOTHING)
		{
			return false;
		}
		switch (position.m_direction)
		{
		case DOWN:
			position.m_Y++;
			break;
		case UP:
			position.m_Y--;
			break;
		case RIGHT:
			position.m_X++;
			break;
		case LEFT:
			position.m_X--;
			break;
		}
	}
	return true;
}

void Player::RenderRemain()
{
	int sumShip = 0;
	for (int i = 0; i < SHIPTYPECOUNT; ++i)
	{
		sumShip += m_NumShip[i];
	}
	SetCursorAndColor(15, (m_MyMap->GetMapSize() + 2) * 2 + FIRST_MAP_GOTOX, BLACK, BLACK);
	for (int i = 0; i < sumShip + 1; ++i)
	{
		printf_s("   ");
	}
	SetCursorPosition(15, (m_MyMap->GetMapSize() + 2) * 2 + FIRST_MAP_GOTOX);
	SetColor(WHITE, BLACK);
	printf_s(" ");
	for (int i = 0; i < SHIPTYPECOUNT; i++)
	{
		for (int j = 0; j < m_NumShip[i]; j++)
		{
			SetColor(GetForeColor((ShipType)i), GetBackColor((ShipType)i));
			printf_s("%s", GetShipChar((ShipType)i).c_str());
			SetColor(WHITE, BLACK);
			printf_s(" ");
		}
	}
}

void Player::SetShipCoords()
{
	int i = 0;
	for (auto ship : m_ShipList)
	{
		ship->AddPosition(m_ShipPositions[i++]);
	}
}

void Player::MarkOnEnemyMap(Coordinate shot, HitResult hitResult)
{
	if (hitResult != MISS)
		m_EnemyMap->SetMapStatus(shot, ATTACKED_SHIP);
	else
		m_EnemyMap->SetMapStatus(shot, ATTACKED_MISS);
}

bool Player::GameOverCheck(HitResult hitResult)
{
	switch (hitResult)
	{
	case DESTROY_AIRCRAFT:
		m_NumShip[(int)AIRCRAFT]--;
		break;
	case DESTROY_BATTLESHIP:
		m_NumShip[(int)BATTLESHIP]--;
		break;
	case DESTROY_CRUISER:
		m_NumShip[(int)CRUISER]--;
		break;
	case DESTROY_DESTROYER:
		m_NumShip[(int)DESTROYER]--;
		break;
	}
	for (int i = 0; i < SHIPTYPECOUNT; ++i)
	{
		if (m_NumShip[i] != 0)
			return false;
	}
	return true;
}

void Player::MarkOnMyMap(Coordinate shot, HitResult hitResult)
{
	if (hitResult != MISS)
		m_MyMap->SetMapStatus(shot, ATTACKED_SHIP);
	else
		m_MyMap->SetMapStatus(shot, ATTACKED_MISS);
}

Coordinate Player::AIAttack(HitResult hitResult)
{
	Coordinate shot;
	
	if (m_AIMemHitResult == MISS)
	{
		shot = RandomAttackOnChecker();
		m_AIMemPosition.m_X = shot.m_X;
		m_AIMemPosition.m_Y = shot.m_Y;
		m_AIMemPosition.m_direction = (Direction)(rand() % 4);
	}
	if (m_AIMemHitResult == HIT)
	{
		if (m_AIMemPosition.m_direction == UP)
		{
			shot.m_Y = m_AIMemPosition.m_Y - 1;
		}
		else if (m_AIMemPosition.m_direction == DOWN)
		{
			shot.m_Y = m_AIMemPosition.m_Y + 1;

		}
		else if (m_AIMemPosition.m_direction == LEFT)
		{
			shot.m_X = m_AIMemPosition.m_X - 1;

		}
		else if (m_AIMemPosition.m_direction == RIGHT)
		{
			shot.m_X = m_AIMemPosition.m_X + 1;
		}
	}
	else if (m_AIMemHitResult == DESTROY_AIRCRAFT || m_AIMemHitResult == DESTROY_BATTLESHIP || m_AIMemHitResult == DESTROY_CRUISER || m_AIMemHitResult == DESTROY_DESTROYER)
	{
		shot = RandomAttackOnChecker();
		m_AIMemPosition.m_X = shot.m_X;
		m_AIMemPosition.m_Y = shot.m_Y;
		m_AIMemPosition.m_direction = (Direction)(rand() % 4);
	}
	m_AIMemHitResult = hitResult;
	return shot;
}

Coordinate Player::RandomAttack()
{
	Coordinate randShot;
	randShot.m_X = rand() % m_MyMap->GetMapSize();
	randShot.m_Y = rand() % m_MyMap->GetMapSize();
	return randShot;
}

Coordinate Player::RandomAttackOnChecker()
{
	Coordinate randShot;
	do 
	{
		randShot.m_X = rand() % m_MyMap->GetMapSize();
		randShot.m_Y = rand() % m_MyMap->GetMapSize();
	} while (randShot.m_X + randShot.m_Y % 2 == 1);
	return randShot;
}

