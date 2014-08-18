#pragma once
#include "Board.h"
#include "Ship.h"
#include "AirCraft.h"
#include "BattleShip.h"
#include "Cruiser.h"
#include "Destroyer.h"

class Player
{
public:
	Player();
	~Player();

public:
	void PlaceShips();
	void Attack();
	HitResult HitCheck(Position p);
	void GiveUp();
	void PrintShips();

protected:
	Board myBoard;
	Board enemyBoard;
	//Ship* shipList;
	AirCraft m_Aircraft;
	BattleShip m_BattleShip;
	Cruiser m_Cruiser;
	Destroyer m_Destroyer[2];

	int type;
};

