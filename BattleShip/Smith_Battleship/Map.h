#pragma once

class Map
{
public:
	Map(int mapSize);
	~Map();
	
	void			ResetMap();
	
	void			SetSizeOfMap(int mapSize) { m_MapSize = mapSize; }
	void			SetMapStatus(Position position, MapStatus mapStatus, ShipType shipType); //for Setting Ship
	void			SetMapStatus(Coordinate shot, MapStatus mapStatus); //for attacking

	int				GetMapSize() { return m_MapSize; }
	MapStatus		GetMapStatus(int x, int y) { return m_Map[y][x]; }
	
	void			RenderMapStatus(int gotoX, int gotoY);

private:
	int				m_MapSize;
	MapStatus**		m_Map;
};