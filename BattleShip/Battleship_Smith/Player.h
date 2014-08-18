#pragma once
#include "stdafx.h"
#include "HeaderSet.h"
#include "Ship.h"
#include "Aircraft.h"
#include "Battleship.h"
#include "Cruiser.h"
#include "Destroyer.h"
#include "Map.h"

class Player
{
public:
	Player();
	~Player();

	//Random Attack이랑 RandomSetShips는 AI 클래스 만들어서 오버라이드가 괜찮을듯 일단은 그냥 두기
	void			SetShips(Coordinate startCoordinate, Direction direction); //Manual Set
	void			RandomSetShips(); //Random Set
	Coordinate		Attack(Coordinate shot);
	void			RandomAttack(); //Random Attack
	HitResult		SendResult(Coordinate shot);
	void			PrintShips(); //GameRender로 옮길까??

protected:
	PlayerType		m_Playertype;
	std::string		m_PlayerName;
	Map*			m_MyMap;
	Map*			m_EnemyMap;
	std::list<Ship*>m_ShipList;
};

