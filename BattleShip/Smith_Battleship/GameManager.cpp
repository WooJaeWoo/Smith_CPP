#include "stdafx.h"
#include "GameManager.h"
#include "GameRenderer.h"

GameManager::GameManager()
{
	m_GameRenderer = new GameRenderer();
	m_GameStatus = TITLE;
}


GameManager::~GameManager()
{
	delete m_GameRenderer;
}

void GameManager::GameRun()
{
	while (true)
	{
		m_GameRenderer->RenderPages(m_GameStatus);
		m_GameStatus = (GameStatus)(((int)m_GameStatus + 1) % 7);
		getchar();
	}
}


