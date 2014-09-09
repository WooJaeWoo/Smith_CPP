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

void Player::SetShip(Ship& ship, Position position)
{

}

void Player::RandomSetShip(Ship& ship)
{

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

bool Player::InvalidPosition(Ship& ship, Position position)
{


}

bool Player::AttackableCheck(Coordinate shot)
{

}*/