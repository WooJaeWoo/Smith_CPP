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

void Player::LocateShips()
{
	for (auto ship : m_ShipList)
	{
		int maxHp = 0;
		maxHp = ship->GetMaxHP();
		ship->SetCurrentHP(maxHp);
		RandomSetShip(*ship);
	}
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
			coordinate.m_X++;
			break;
		default:
			printf_s("Error: invalid direction");
			break;
		}
	}
}

bool Player::OverlabCheck(Ship& ship, Coordinate coordinate, Direction direction)
{
	int maxHP = ship.GetMaxHP();
	Coordinate original = coordinate;

	for (auto shipInList : m_ShipList)
	{
		coordinate = original;
		for (int i = 0; i < maxHP; i++)
		{
			if (shipInList->Overlab(coordinate, direction))
				return true;
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
				coordinate.m_X++;
				break;
			default:
				break;
			}
		}
	}
	return false;
}

bool Player::InvalidPosition(Ship& ship, Coordinate coordinate, Direction direction)
{
	int maxSize = m_MyMap->GetMaxSizeofMap();
	int maxHp = ship.GetMaxHP();

	switch (direction)
	{
		case UP:
			if (coordinate.m_Y < maxHp - 1 || coordinate.m_Y >= maxSize)
				return true;
			else
				return false;
			break;
		case DOWN:
			if (coordinate.m_Y < 0 || coordinate.m_Y > maxSize - maxHp)
				return true;
			else
				return false;
			break;
		case LEFT:
			if (coordinate.m_X < maxHp - 1 || coordinate.m_X >= maxSize)
				return true;
			else
				return false;
			break;
		case RIGHT:
			if (coordinate.m_X < 0 || coordinate.m_X > maxSize - maxHp)
				return true;
			else
				return false;
			break;
		default:
			printf_s("Error: Invalid Position");
			return true;
			break;
	}

}

void Player::RandomSetShip(Ship& ship)
{
	Coordinate coordinate;
	Direction direction;
	do 
	{
		coordinate.m_X = rand() % m_MyMap->GetMaxSizeofMap();
		coordinate.m_Y = rand() % m_MyMap->GetMaxSizeofMap();
		direction = (Direction)(rand() % 4);
	} while (m_MyMap->OutOfBoundary(coordinate) || InvalidPosition(ship, coordinate, direction) || OverlabCheck(ship, coordinate, direction));
	SetShip(ship, coordinate, direction);
}

Coordinate Player::Attack(Coordinate shot)
{
	if (m_EnemyMap->IsNOTHING(shot) && !m_MyMap->OutOfBoundary(shot))
	{
		return shot;
	}
	else if (m_MyMap->OutOfBoundary(shot))
	{
		printf_s("Wrong Coordinate!");
		//다시 공격할 수 있는 함수 호출해주기
	}
	else
	{
		printf_s("This Coordinate has been ATTACKED!");
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
	} while (!m_EnemyMap->IsNOTHING(shot) && m_MyMap->OutOfBoundary(shot));
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