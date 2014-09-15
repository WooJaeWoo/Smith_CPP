#include "stdafx.h"
#include "Ship.h"


Ship::Ship()
{
}


Ship::~Ship()
{
}

void Ship::ResetShip()
{
	m_CurrentHP = m_MaxHP;
	m_ShipCoords.clear();
}

void Ship::AddPosition(Position position)
{
	Coordinate shipCoord;
	shipCoord.m_X = position.m_X;
	shipCoord.m_Y = position.m_Y;
	for (int i = 0; i < m_MaxHP; ++i)
	{
		m_ShipCoords.push_back(shipCoord);
		switch (position.m_direction)
		{
		case DOWN:
			shipCoord.m_Y++;
			break;
		case UP:
			shipCoord.m_Y--;
			break;
		case LEFT:
			shipCoord.m_X--;
			break;
		case RIGHT:
			shipCoord.m_X++;
			break;
		}
	}
}

HitResult Ship::HitCheck(Coordinate shot)
{
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