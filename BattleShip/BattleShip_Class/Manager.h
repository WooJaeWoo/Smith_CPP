#pragma once
#include "Ship.h"
#include "Map.h"

class Manager
{
public:
	Manager();
	~Manager();
	void Turn_Manager();
	void Game_Over();
	void Check_Ship_Attacked(Map submitted_Map, Ship * ships);
};

