#include "stdafx.h"
#include "Player.h"


Player::Player()
{
	m_MyMap = new Map();
	m_EnemyMap = new Map();
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

void Player::SetShips(Coordinate startCoordinate, Direction direction)
{

}

void Player::RandomSetShips()
{
	Coordinate startCoordinate;
	startCoordinate.m_X = rand() % m_MyMap->GetMaxSizeofMap();
	startCoordinate.m_Y = rand() % m_MyMap->GetMaxSizeofMap();
	Direction direction = static_cast<Direction>(rand() % 4);
	SetShips(startCoordinate, direction);
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

HitResult Player::SendResult( Coordinate shot)
{

}

void Player::PrintShips()
{

}