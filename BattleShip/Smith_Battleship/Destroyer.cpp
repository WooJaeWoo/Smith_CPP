#include "stdafx.h"
#include "Destroyer.h"


Destroyer::Destroyer()
{
	m_Name = "Destroyer";
	m_Shiptype = DESTROYER;
	m_MaxHP = 2;
	m_CurrentHP = m_MaxHP;
}


Destroyer::~Destroyer()
{
}
