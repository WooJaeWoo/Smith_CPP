#include "stdafx.h"
#include "GameSetting.h"


GameSetting::GameSetting()
{

	m_NumShip.push_back(1);
	m_NumShip.push_back(1);
	m_NumShip.push_back(1);
	m_NumShip.push_back(2);
}


GameSetting::~GameSetting()
{
}

void GameSetting::SetNumShip(std::vector<int> numShip)
{
	for (int i = 0; i < m_ShipTypeCount; i++)
	{
		m_NumShip[i] = numShip[i];
	}
}
