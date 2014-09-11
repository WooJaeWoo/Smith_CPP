#pragma once
#include "stdafx.h"

class Ship
{
public:
	Ship();
	virtual ~Ship();

	int						GetCurrentHP() { return m_CurrentHP; }
	void					SetCurrentHP(int hp) { m_CurrentHP = hp; }
	ShipType				GetShipType() { return m_Shiptype; }

	void					AddPosition(Position position);
	HitResult				HitCheck(Coordinate shot);

protected:
	std::string				m_Name;
	ShipType				m_Shiptype;
	std::vector<Position>	m_ShipCoords;
	int						m_MaxHP;
	int						m_CurrentHP;
};

