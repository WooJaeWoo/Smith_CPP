#include "stdafx.h"
#include "Ship.h"
#include "Player.h"


Ship::Ship()
{
}


Ship::~Ship()
{
}

HitResult Ship::HitCheck(Coordinate coordinate)
{
	coordinate.m_X = tolower(coordinate.m_X);

	for (int i = 0; i < m_MaxHP; i++)
	{
		if (m_ShipCoords[i].m_X == coordinate.m_X && m_ShipCoords[i].m_Y == coordinate.m_Y)
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

void Ship::AddPosition(Coordinate coordinate)
{
	coordinate.m_X = tolower(coordinate.m_X);
	m_ShipCoords.push_back(coordinate);
}

void Ship::AddPosition(char x, char y)
{
	Coordinate coordinate;
	coordinate.m_X = x;
	coordinate.m_Y = y;

	AddPosition(coordinate);
}

void Ship::PrintCoordnates()
{
	printf_s("Coordinates of %s: ", m_Name.c_str());
	for (int i = 0; i < m_MaxHP; i++)
	{
		printf_s("%c%c ", 'a' + m_ShipCoords[i].m_X, '1' + m_ShipCoords[i].m_Y);
	}
	printf_s("\n");
}

bool Ship::Overlab(Coordinate coordinate, Direction direction)
{	
	for (auto shipCoord : m_ShipCoords)
	{
		if (shipCoord.m_X == coordinate.m_X && shipCoord.m_Y == coordinate.m_Y)
			return true;
	}
	return false;
}