#pragma once

class Map
{
public:
	Map(int maxSize);
	~Map();

	int			GetMaxSizeofMap() { return m_MaxSize; }
	void		SetMaxSizeofMap(int maxSize) { m_MaxSize = maxSize; }
	void		SetMapStatus(Coordinate shot, HitResult hitresult);
	void		PrintMap();
	bool		IsNOTHING(Coordinate coordinate);
	bool		OutOfBoundary(Coordinate coordinate);

private:
	int			m_MaxSize;
	HitResult**	m_map;
};