#pragma once
#include "stdafx.h"

class Ship;
class Map;

class Player
{
public:
	Player();
	~Player();

	void				MakeMaps(int mapSize);
	void				MakeShips();

	void				SetShip(Ship& ship, Coordinate coordinate, Direction direction); //Manual Set
	void				RandomSetShip(Ship& ship);
	bool				InvalidPosition(Ship& ship, Coordinate coordinate, Direction direction);
	bool				OverlabCheck(Ship& ship, Coordinate coordinate, Direction direction);
	void				LocateShips();

	void				SetNumShip(std::vector<int> numShip);
	std::vector<Ship*>	GetShipList() { return m_ShipList; }
	Map*				GetMyMap() { return m_MyMap; }
	Map*				GetEnemyMap() { return m_EnemyMap; }

	Coordinate			AttackableCheck(Coordinate shot);
	Coordinate			RandomAttack();
	HitResult			SendResult(Coordinate shot);

	void				PrintShips();

private:
	PlayerType			m_Playertype;
	std::string			m_PlayerName;
	Map*				m_MyMap;
	Map*				m_EnemyMap;
	std::vector<int>	m_NumShip;
	std::vector<Ship*>	m_ShipList;
};

