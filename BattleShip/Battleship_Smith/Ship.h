#pragma once
#include "stdafx.h"

class Player;

class Ship
{

public:
	Ship();
	virtual ~Ship();

	std::string				GetName() { return m_Name; }
	int						GetMaxHP() { return m_MaxHP; }
	int						GetCurrentHP() { return m_CurrentHP; }
	void					SetCurrentHP(int _hp) { m_CurrentHP = _hp; }

	void					AddPosition(Coordinate coordinate);
	void					AddPosition(char x, char y);
	HitResult				HitCheck(Coordinate coordinate);
	bool					Overlab(Coordinate coordinate, Direction direction);

	void					PrintCoordnates();

protected:
	std::string				m_Name;
	ShipType				m_Shiptype;
	std::vector<Coordinate>	m_ShipCoords;
	int						m_MaxHP;
	int						m_CurrentHP;
};
