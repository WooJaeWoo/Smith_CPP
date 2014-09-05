#pragma once
#include "stdafx.h"

class Ship
{
public:
	Ship();
	~Ship();


protected:
	std::string				m_Name;
	ShipType				m_Shiptype;
	std::vector<Position>	m_ShipCoords;
	int						m_MaxHP;
	int						m_CurrentHP;
};

