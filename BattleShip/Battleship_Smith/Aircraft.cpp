#include "stdafx.h"
#include "Aircraft.h"


Aircraft::Aircraft()
{
	m_Name = "Aircraft";
	m_Shiptype = AIRCRAFT;
	m_MaxHP = 5;
	m_CurrentHP = m_MaxHP;
}


Aircraft::~Aircraft()
{
}
