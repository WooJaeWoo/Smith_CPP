#include "stdafx.h"
#include "Ship.h"
#include "Player.h"


Ship::Ship()
{
	m_player = new Player();
	memset(m_Coordinate, 0, sizeof(Coordinate) * m_player->GetShipCount());
}


Ship::~Ship()
{
	delete m_player;
}

HitResult Ship::HitCheck(Coordinate coordinate)
{
	coordinate.m_X = tolower(coordinate.m_X);

	for (int i = 0; i < m_MaxHP; i++)
	{
		if (m_Coordinate[i].m_X == coordinate.m_X && m_Coordinate[i].m_Y == coordinate.m_Y)
		{
			m_Coordinate[i].m_X = -1;
			m_Coordinate[i].m_Y = -1;
			//왜 좌표를 옮겨버리는 것인가?
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
	
	for (int i = 0; i < m_MaxHP; i++)
	{
		m_Coordinate[i].m_X = coordinate.m_X;
		m_Coordinate[i].m_Y = coordinate.m_Y;
		//m_Coordinate[i] = coordinate;
	}
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
		printf_s("%c%c ", m_Coordinate[i].m_X, m_Coordinate[i].m_Y);
	}
	printf_s("\n");
}