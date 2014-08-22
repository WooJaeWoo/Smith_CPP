#include "stdafx.h"
#include "Ship.h"

Ship::Ship()
{
	m_HP = 0;
	memset(m_Pos, 0, sizeof(Position)* 5);
}

Ship::~Ship()
{
}

void Ship::AddPosition(Position pos)
{
	pos.m_X = (char)tolower(pos.m_X);

	for (int i = 0; i < m_MaxHP; i++)
	{
		if (m_Pos[i].m_X == pos.m_X && m_Pos[i].m_Y == pos.m_Y)
		{
			printf_s("ERROR : Already Exist\n");
			return;
		}
	}

	for (int i = 0; i < m_MaxHP; i++)
	{
		if (m_Pos[i].m_X == 0)
		{
			m_Pos[i].m_X = pos.m_X;
			m_Pos[i].m_Y = pos.m_Y;
			
			break;
		}
	}
}

void Ship::AddPosition(char x, char y)
{
	Position pos;

	pos.m_X = x;
	pos.m_Y = y;
	AddPosition(pos);
}

std::string Ship::GetName()
{
	return m_Name;
}
HitResult Ship::HitCheck(Position hitPos)
{
	hitPos.m_X = (char)tolower(hitPos.m_X);

	for (int i = 0; i < m_MaxHP; i++)
	{
		if (m_Pos[i].m_X == hitPos.m_X && m_Pos[i].m_Y == hitPos.m_Y)
		{
			m_Pos[i].m_X = 0;
			m_Pos[i].m_Y = 0;
			m_HP--;

			switch (m_Type)
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
				printf_s("Ship.cpp : HitCheck - MAKE NEW CASE\n");
				break;
			}

			return HIT;
		}
	}

	return MISS;
}

bool Ship::CheckPosition(char x, char y)
{
	for (int i = 0; i < m_MaxHP; i++)
	{
		if (m_Pos[i].m_X == x && m_Pos[i].m_Y == y)
		{
			return true;
		}
	}
	return false;
}
void Ship::Print()
{
	printf_s("%s HP : %d\n", m_Name.c_str(), m_HP);
}

void Ship::PrintPositions()
{
	printf_s("%s: ", m_Name.c_str());
	for (int i = 0; i < GetMaxHP(); i++)
	{
		printf_s("%c%c ", m_Pos[i].m_X, m_Pos[i].m_Y);
	}
	printf_s("\n");
}

int Ship::GetMaxHP()
{
	return m_MaxHP;
}