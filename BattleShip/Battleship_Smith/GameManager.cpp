#include "stdafx.h"
#include "GameManager.h"
#include "Player.h"
#include "Ship.h"
#include "Map.h"

GameManager::GameManager()
{
	player1 = new Player();
	player2 = new Player();

}


GameManager::~GameManager()
{
	delete player1;
	delete player2;
}
