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

void Map::SetMapStatus(Coordinate shot, MapStatus mapStatus)
{
	m_Map[shot.m_X][shot.m_Y] = mapStatus;
}

void Map::SetMapStatus(Position position, MapStatus mapStatus, ShipType shipType)
{
	for (int i = 0; i < GetMaxHP(shipType); ++i)
	{
		m_Map[position.m_X][position.m_Y] = mapStatus;
		switch (position.m_direction)
		{
		case DOWN:
			position.m_X++;
			break;
		case UP:
			position.m_X--;
			break;
		case LEFT:
			position.m_Y--;
			break;
		case RIGHT:
			position.m_Y++;
			break;
		}
	}
}

bool Map::IsNOTHING(Position position, ShipType shipType)
{
	int maxHP = SHIPTYPECOUNT + 1 - (int)shipType;
	for (int i = 0; i < maxHP; ++i)
	{
		if (GetMapStatus(position.m_X, position.m_Y) != NOTHING)
			return false;
		switch (position.m_direction)
		{
		case DOWN:
			position.m_X++;
			break;
		case UP:
			position.m_X--;
			break;
		case RIGHT:
			position.m_Y++;
			break;
		case LEFT:
			position.m_Y--;
			break;
		}
	}
	return true;
}

bool Map::OutOfBoundary(Coordinate coordinate)
{
	if (coordinate.m_X < 0 || coordinate.m_X > m_MapSize - 1
		|| coordinate.m_Y < 0 || coordinate.m_Y > m_MapSize - 1)
		return true;
	else
		return false;
}