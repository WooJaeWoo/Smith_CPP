#pragma once
class Map
{
public:
	Map(int mapSize);
	~Map();

	void SetSizeOfMap(int mapSize) { m_MapSize = mapSize; }
	void SetMapStatus(Position position, MapStatus mapStatus, ShipType shipType);
	void SetMapStatus(Coordinate shot, MapStatus mapStatus);
	
	MapStatus GetMapStatus(int x, int y) { return m_Map[x][y]; }
	
	bool IsNOTHING(Position position, ShipType shipType);
	bool OutOfBoundary(Coordinate coordinate);

private:
	int m_MapSize;
	MapStatus** m_Map;
};

