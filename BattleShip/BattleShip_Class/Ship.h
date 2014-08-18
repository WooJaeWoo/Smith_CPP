#pragma once
#include<string>

struct Position
{
	char m_X;
	char m_Y;
};

enum HitResult
{
	HIT,
	MISS,
	DESTROY_AIRCRAFT,
	DESTROY_BATTLESHIP,
	DESTROY_CRUISER,
	DESTROY_DESTROYER,
};

enum ShipType
{
	DESTROYER,
	CRUISER,
	BATTLESHIP,
	AIRCRAFT,
};


class Ship
{
public:
	Ship();
	~Ship();

	void AddPosition(Position pos);
	void AddPosition(char x, char y);
	HitResult HitCheck(Position hitPos);
	bool CheckPosition(char x, char y);
	int GetHP();
	int GetMaxHP();
	std::string GetName();
	void Print();
	void PrintPositions();

protected:
	std::string m_Name;
	ShipType m_Type;
	Position m_Pos[5];
	int m_HP;
	int m_MaxHP;
};