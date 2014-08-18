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

	//Random Attack�̶� RandomSetShips�� AI Ŭ���� ���� �������̵尡 �������� �ϴ��� �׳� �α�
	void			SetShips(Coordinate startCoordinate, Direction direction); //Manual Set
	void			RandomSetShips(); //Random Set
	Coordinate		Attack(Coordinate shot);
	void			RandomAttack(); //Random Attack
	HitResult		SendResult(Coordinate shot);
	void			PrintShips(); //GameRender�� �ű��??

protected:
	PlayerType		m_Playertype;
	std::string		m_PlayerName;
	Map*			m_MyMap;
	Map*			m_EnemyMap;
	std::list<Ship*>m_ShipList;
};

