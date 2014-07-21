#pragma once
class Map
{
public:
	Map();
	~Map();
	void MarkAttack(int x, int y);
	void Render();

private:
	bool ** coordinate;

};

