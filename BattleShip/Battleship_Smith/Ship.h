#pragma once
#include "HeaderSet.h"
#include "stdafx.h"

class Player;

class Ship
{

public:
	Ship();
	virtual ~Ship();

	std::string		GetName() { return m_Name; }
	int				GetMaxHP() { return m_MaxHP; }
	int				GetCurrentHP() { return m_CurrentHP; }
	void			AddPosition(Coordinate coordinate);
	void			AddPosition(char x, char y);
	HitResult		HitCheck(Coordinate coordinate);
	void			PrintCoordnates();

protected:
	Player*			m_player;
	std::string		m_Name;
	ShipType		m_Shiptype;
	Coordinate		m_Coordinate[5];
	int				m_MaxHP;
	int				m_CurrentHP;
};

//좌표 유효성 판정 범위
//Up Y: maxHP - 1 ~ maxSize
//DownY: 1 ~ maxSize - maxHP + 1
//Left X: maxHP - 1 ~ maxSize
//Right X: 1 ~ maxSize - maxHP + 1
