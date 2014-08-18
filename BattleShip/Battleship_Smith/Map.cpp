#include "stdafx.h"
#include "Map.h"


Map::Map()
{
	m_MaxSize = 8;
	m_map = new HitResult*[m_MaxSize];
	for (int i = 0; i < m_MaxSize; i++)
	{
		m_map[i] = new HitResult[m_MaxSize];
		for (int j = 0; j < m_MaxSize; ++j) //왜 ++이 앞에 붙는 것인가?
		{
			m_map[i][j] = NOTHING;
		}
	}
}

Map::~Map()
{
}

bool Map::IsNOTHING(Coordinate coordinate)
{
	return m_map[coordinate.m_X][coordinate.m_Y] == NOTHING;
}
