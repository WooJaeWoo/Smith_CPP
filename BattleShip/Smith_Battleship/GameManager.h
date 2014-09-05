#pragma once
#include "HeaderSet.h"

class GameRenderer;

class GameManager
{
public:
	GameManager();
	~GameManager();

	void	GameRun();

private:
	GameRenderer* m_GameRenderer;
	GameStatus m_GameStatus;


};

