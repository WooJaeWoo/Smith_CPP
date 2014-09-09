#include "stdafx.h"
#include "Ship.h"


Ship::Ship()
{
}


Ship::~Ship()
{
}

void Ship::AddPosition(Position position)
{
	position.m_X = tolower(position.m_X);
	m_ShipCoords.push_back(position);
}

HitResult Ship::HitCheck(Coordinate shot)
{
	shot.m_X = tolower(shot.m_X);
	for (int i = 0; i < m_MaxHP; i++)
	{
		if (m_ShipCoords[i].m_X == shot.m_X && m_ShipCoords[i].m_Y == shot.m_Y)
		{
			m_ShipCoords[i].m_X = -1;
			m_ShipCoords[i].m_Y = -1;
			m_CurrentHP--;
			if (m_CurrentHP == 0)
			{
				switch (m_Shiptype)
				{
				case AIRCRAFT:
					return DESTROY_AIRCRAFT;
				case BATTLESHIP:
					return DESTROY_BATTLESHIP;
				case CRUISER:
					return DESTROY_CRUISER;
				case DESTROYER:
					return DESTROY_DESTROYER;
				default:
					printf_s("Error: Invalid ship type");
					break;
				}
			}
			return HIT;
		}
	}
	return MISS;
}