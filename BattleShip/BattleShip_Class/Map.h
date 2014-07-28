#pragma once
class Map
{
public:
	Map();
	~Map();
	void MarkAttack(char x, char y);
	void Render();

private:
	bool coordinate[8][8];
};

