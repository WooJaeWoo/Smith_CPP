#pragma once
#include "Map.h"
#include "Ship.h"

enum PlayerName
{
	NORMAL =  100, 
	AI = 300, 
	NETWORK = 500,
};

typedef struct
{
	int x;
}t_x;

struct XPosition
{
	int x;
};

struct Position
{
	char x;
	char y;
};

typedef int t_x;

class Player
{
public:
	Player();
	~Player();
	void Locate_Ships();
	void Attack();
	Map Submit_map(std::string playerName)
	{
		playerName = playerName;
	}

private:
	std::string mPlayerName;
	PLAYER_TYPE mPlayer_type;
	
	Map m_MyMap;
	Ship* m_MyShips;
	Ship targetShip;

};