#pragma once
#include "Map.h"
#include "Ship.h"

enum PLAYER_TYPE {NORMAL, AI, NETWORK};

class Player
{
public:
	Player();
	~Player();
	void Locate_Ships();
	void Attack();
	Map Submit_map();

private:
	std::string playerName;
	PLAYER_TYPE player_type;
	Map myMap;
	Ship * myShips;

};