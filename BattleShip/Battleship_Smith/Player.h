#pragma once
#include "stdafx.h"
#include "HeaderSet.h"

class Ship;
class Map;

class Player
{
public:
	Player();
	~Player();

	void				SetShip(Ship& ship, Coordinate coordinate, Direction direction); //Manual Set
	void				RandomSetShip(Ship& ship);
	Coordinate			Attack(Coordinate shot);
	void				RandomAttack();
	HitResult			SendResult(Coordinate shot);
	void				PrintShips();
	int					GetShipCount() { return m_ShipCount; }

protected:
	int					m_ShipCount;
	PlayerType			m_Playertype;
	std::string			m_PlayerName;
	Map*				m_MyMap;
	Map*				m_EnemyMap;
	std::list<Ship*>	m_ShipList;
};

