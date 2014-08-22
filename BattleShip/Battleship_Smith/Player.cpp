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
	m_MyMap = new Map();
	m_EnemyMap = new Map();
	m_ShipCount = 5;
	m_ShipList.push_back(new Aircraft());
	m_ShipList.push_back(new Battleship());
	m_ShipList.push_back(new Cruiser());
	m_ShipList.push_back(new Destroyer());
	m_ShipList.push_back(new Destroyer());
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

void Player::SetShip(Ship& ship, Coordinate coordinate, Direction direction)
{
	for (int i = 0; i < ship.GetMaxHP(); i++)
	{
		ship.AddPosition(coordinate);
		switch (direction)
		{
		case UP:
			coordinate.m_Y--;
			break;
		case DOWN:
			coordinate.m_Y++;
			break;
		case LEFT:
			coordinate.m_X--;
			break;
		case RIGHT:
			coordinate.m_Y--;
			break;
		default:
			printf_s("Error: invalid direction");
			break;
		}
	}
}

void Player::RandomSetShip(Ship& ship)
{
	Coordinate startCoordinate;
	startCoordinate.m_X = rand() % m_MyMap->GetMaxSizeofMap();
	startCoordinate.m_Y = rand() % m_MyMap->GetMaxSizeofMap();
	Direction direction = static_cast<Direction>(rand() % 4);
	SetShip(ship, startCoordinate, direction);
}

Coordinate Player::Attack(Coordinate shot)
{
	if (m_EnemyMap->IsNOTHING(shot))
	{
		return shot;
	}
	else
	{
		printf_s("This coordinate has been ATTACKED!");
		//다시 공격할 수 있는 함수 호출해주기
	}
}

void Player::RandomAttack()
{
	Coordinate shot;
	do 
	{
		shot.m_X = rand() % m_MyMap->GetMaxSizeofMap();
		shot.m_Y = rand() % m_MyMap->GetMaxSizeofMap();
	} while (!m_EnemyMap->IsNOTHING(shot));
	Attack(shot);
}

HitResult Player::SendResult(Coordinate shot)
{
	HitResult hitresult = NOTHING;
	for (auto ship : m_ShipList)
	{
		hitresult = ship->HitCheck(shot);
		if (hitresult != MISS)
			return hitresult;
	}
	return MISS;
}

void Player::PrintShips()
{
	for (auto ship : m_ShipList)
	{
		ship->PrintCoordnates();
	}
}