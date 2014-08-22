#pragma once
#include "HeaderSet.h"

class Map
{
public:
	Map();
	~Map();

	int			GetMaxSizeofMap() { return m_MaxSize; }
	void		SetMap(Coordinate shot, HitResult hitresult);
	void		PrintMap();
	bool		IsNOTHING(Coordinate coordinate);

protected:
	int			m_MaxSize;
	HitResult**	m_map;
};