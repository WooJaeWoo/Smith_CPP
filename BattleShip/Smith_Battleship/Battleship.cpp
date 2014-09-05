#include "stdafx.h"
#include "Battleship.h"


Battleship::Battleship()
{
	m_Name = "Battleship";
	m_Shiptype = BATTLESHIP;
	m_MaxHP = 4;
	m_CurrentHP = m_MaxHP;
}


Battleship::~Battleship()
{
}
