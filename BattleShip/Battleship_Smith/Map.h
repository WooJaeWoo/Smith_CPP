#pragma once
#include "HeaderSet.h"

class Map
{
public:
	Map();
	~Map();

	int			GetMaxSizeofMap() { return m_MaxSize; }
	void		SetMaxSizeofMap(int _maxSize) { m_MaxSize = _maxSize; }
	void		SetMap(Coordinate shot, HitResult hitresult);
	void		PrintMap();
	bool		IsNOTHING(Coordinate coordinate);
	bool		OutOfBoundary(Coordinate coordinate);

private:
	int			m_MaxSize;
	HitResult**	m_map;
};