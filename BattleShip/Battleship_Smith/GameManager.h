#pragma once
#include "HeaderSet.h"

class Player;
class Map;
class Ship;

class GameManager
{
public:
	GameManager();
	~GameManager();


protected:
	Player* player1;
	Player* player2;
};

