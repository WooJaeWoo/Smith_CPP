#include "stdafx.h"
#include "Player.h"
#include "Map.h"
#include "Ship.h"
#include "Aircraft.h"
#include "Battleship.h"
#include "Cruiser.h"
#include "Destroyer.h"

Player::Player()
{
}


Player::~Player()
{
	delete m_MyMap;
	delete m_EnemyMap;
	for (auto Ship : m_ShipList)
	{
		delete Ship;
		Ship = nullptr;
	}
	m_ShipList.clear();
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
}

void Player::RenderUpdateMapStatus(int gotoX, int gotoY)
{
	m_MyMap->RenderMapStatus(gotoX, gotoY);
}

Position Player::RandomSetShip(ShipType shipType)
{
	Position position;
	position.m_X = rand() % m_MyMap->GetMapSize();
	position.m_Y = rand() % m_MyMap->GetMapSize();
	position.m_direction = (Direction)(rand() % 4);
	return position;
}

/*Coordinate Player::Attack()
{

}

Coordinate Player::RandomAttack()
{

}

HitResult Player::SendResult(Coordinate shot)
{

}

bool Player::AttackableCheck(Coordinate shot)
{

}*/


bool Player::IsValidSet(Position position, ShipType shipType)
{
	int maxHP = GetMaxHP(shipType);
	for (int i = 0; i < maxHP; ++i)
	{
		if (position.m_X < 0 || position.m_X > m_MyMap->GetMapSize() - 1
			|| position.m_Y < 0 || position.m_Y > m_MyMap->GetMapSize() - 1)
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
	SetCursorAndColor(15, (m_MyMap->GetMapSize() + 2) * 2 + 9, BLACK, BLACK);
	for (int i = 0; i < sumShip + 1; ++i)
	{
		printf_s("   ");
	}
	SetCursorPosition(15, (m_MyMap->GetMapSize() + 2) * 2 + 9);
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

void Player::InitializeMyStatus()
{
	//배 좌표 클리어
	m_MyMap->InitializeMap();
}
