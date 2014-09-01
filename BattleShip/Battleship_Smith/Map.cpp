#include "stdafx.h"
#include "Map.h"


Map::Map(int maxSize)
{
	m_MaxSize = maxSize;
	m_map = new HitResult*[m_MaxSize];
	for (int i = 0; i < m_MaxSize; i++)
	{
		m_map[i] = new HitResult[m_MaxSize];
		for (int j = 0; j < m_MaxSize; ++j)
		{
			m_map[i][j] = NOTHING;
		}
	}
}

Map::~Map()
{
	for (int i = 0; i < m_MaxSize; i++)
	{
		delete m_map[i];
	}
	delete m_map;
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
	if (coordinate.m_X < 0 || coordinate.m_X > m_MaxSize - 1
		|| coordinate.m_Y < 0 || coordinate.m_Y > m_MaxSize -1)
		return true;
	else
		return false;
}
