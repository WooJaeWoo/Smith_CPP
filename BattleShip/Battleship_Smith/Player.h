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

	//int				GetShipCount() { return m_ShipCount; }


	void				SetShip(Ship& ship, Coordinate coordinate, Direction direction); //Manual Set
	void				RandomSetShip(Ship& ship);
	bool				InvalidPosition(Ship& ship, Coordinate coordinate, Direction direction);
	bool				OverlabCheck(Ship& ship, Coordinate coordinate, Direction direction);
	void				LocateShips();

	Coordinate			Attack(Coordinate shot);
	void				RandomAttack();
	HitResult			SendResult(Coordinate shot);

	void				PrintShips();

private:
	int					m_ShipCount;
	PlayerType			m_Playertype;
	std::string			m_PlayerName;
	Map*				m_MyMap;
	Map*				m_EnemyMap;
	std::list<Ship*>	m_ShipList;
};

