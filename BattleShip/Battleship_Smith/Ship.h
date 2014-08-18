#pragma once
#include "HeaderSet.h"
#include "stdafx.h"

class Ship
{

public:
	Ship();
	~Ship();

	std::string		GetName() { return m_Name; }
	int				GetMaxHP() { return m_MaxHP; }
	int				GetCurrentHP() { return m_CurrentHP; }
	void			AddPosition(Coordinate coordinate);
	void			AddPosition(char x, char y);
	HitResult		HitCheck(Coordinate coordinate);
	void			Print();

protected:
	std::string		m_Name;
	ShipType		m_Shiptype;
	Coordinate		m_Coordinate[5];
	int				m_MaxHP;
	int				m_CurrentHP;
};