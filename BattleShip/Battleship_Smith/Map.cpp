#include "stdafx.h"
#include "Map.h"


Map::Map(int mapSize)
{
	m_MapSize = mapSize;
	m_map = new HitResult*[m_MapSize];
	for (int i = 0; i < m_MapSize; ++i)
	{
		m_map[i] = new HitResult[m_MapSize];
		for (int j = 0; j < m_MapSize; ++j)
		{
			m_map[i][j] = NOTHING;
		}
	}
}

Map::~Map()
{
	for (int i = 0; i < m_MapSize; i++)
	{
		delete m_map[i];
	}
	delete m_map;
}

void Map::IntializeMap()
{
	for (int i = 0; i < m_MapSize; ++i)
	{
		for (int j = 0; j < m_MapSize; ++j)
		{
			m_map[i][j] = NOTHING;
		}
	}
}

bool Map::IsNOTHING(Coordinate coordinate)
{
	return m_map[coordinate.m_X][coordinate.m_Y] == NOTHING;
}

void Map::SetMapStatus(Coordinate shot, HitResult hitresult)
{
	m_map[shot.m_X][shot.m_Y] = hitresult;
}

bool Map::OutOfBoundary(Coordinate coordinate)
{
	coordinate.m_X = tolower(coordinate.m_X);
	if (coordinate.m_X < 0 || coordinate.m_X > m_MapSize - 1
		|| coordinate.m_Y < 0 || coordinate.m_Y > m_MapSize -1)
		return true;
	else
		return false;
}
