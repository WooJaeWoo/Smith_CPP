#include "stdafx.h"
#include "Map.h"

Map::Map(int mapSize)
{
	m_MapSize = mapSize;
	m_Map = new MapStatus*[m_MapSize];
	for (int i = 0; i < m_MapSize; ++i)
	{
		m_Map[i] = new MapStatus[m_MapSize];
		for (int j = 0; j < m_MapSize; ++j)
		{
			m_Map[i][j] = NOTHING;
		}
	}
}

Map::~Map()
{
	for (int i = 0; i < m_MapSize; ++i)
	{
		delete m_Map[i];
	}
	delete m_Map;
}

void Map::ResetMap()
{
	for (int i = 0; i < m_MapSize; ++i)
	{
		for (int j = 0; j < m_MapSize; ++j)
		{
			m_Map[i][j] = NOTHING;
		}
	}
}

void Map::SetMapStatus(Coordinate shot, MapStatus mapStatus) //for Attack
{
	m_Map[shot.m_Y][shot.m_X] = mapStatus;
}

void Map::SetMapStatus(Position position, MapStatus mapStatus, ShipType shipType) //for SetShips
{
	for (int i = 0; i < GetMaxHP(shipType); ++i)
	{
		m_Map[position.m_Y][position.m_X] = mapStatus;
		switch (position.m_direction)
		{
		case DOWN:
			position.m_Y++;
			break;
		case UP:
			position.m_Y--;
			break;
		case LEFT:
			position.m_X--;
			break;
		case RIGHT:
			position.m_X++;
			break;
		}
	}
}

void Map::RenderMapStatus(int gotoX, int gotoY)
{
	MapStatus mapStatus;
	for (int i = 0; i < m_MapSize; ++i)
	{
		for (int j = 0; j < m_MapSize; ++j)
		{
			mapStatus = m_Map[j][i];
			switch (mapStatus)
			{
			case NOTHING:
				SetCursorAndColor(i * 4 + gotoX, j * 2 + gotoY, BLACK, BLACK);
				printf_s("  ");
				break;
			case SHIP_AIRCRAFT:
				SetCursorAndColor(i * 4 + gotoX, j * 2 + gotoY, GetForeColor(AIRCRAFT), GetBackColor(AIRCRAFT));
				printf_s("%s", GetShipChar(AIRCRAFT).c_str());
				break;
			case SHIP_BATTLESHIP:
				SetCursorAndColor(i * 4 + gotoX, j * 2 + gotoY, GetForeColor(BATTLESHIP), GetBackColor(BATTLESHIP));
				printf_s("%s", GetShipChar(BATTLESHIP).c_str());
				break;
			case SHIP_CRUISER:
				SetCursorAndColor(i * 4 + gotoX, j * 2 + gotoY, GetForeColor(CRUISER), GetBackColor(CRUISER));
				printf_s("%s", GetShipChar(CRUISER).c_str());
				break;
			case SHIP_DESTROYER:
				SetCursorAndColor(i * 4 + gotoX, j * 2 + gotoY, GetForeColor(DESTROYER), GetBackColor(DESTROYER));
				printf_s("%s", GetShipChar(DESTROYER).c_str());
				break;
			case ATTACKED_SHIP:
				SetCursorAndColor(i * 4 + gotoX, j * 2 + gotoY, BLACK, DARK_RED);
				printf_s("£È");
				break;
			case ATTACKED_MISS:
				SetCursorAndColor(i * 4 + gotoX, j * 2 + gotoY, WHITE, GRAY);
				printf_s("£Í");
				break;
			}
		}
	}
}
