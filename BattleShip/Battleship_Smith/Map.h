#pragma once

class Map
{
public:
	Map(int maxSize);
	~Map();


	int			GetMaxSizeofMap() { return m_MapSize; }
	void		SetMaxSizeofMap(int mapSize) { m_MapSize = mapSize; }
	void		SetMapStatus(Coordinate shot, HitResult hitresult);
	void		PrintMap();
	bool		IsNOTHING(Coordinate coordinate);
	bool		OutOfBoundary(Coordinate coordinate);

private:
	int			m_MapSize;
	HitResult**	m_map;
};