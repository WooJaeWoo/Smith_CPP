#include "stdafx.h"
#include "Player.h"


Player::Player()
{

}

Player::~Player()
{

}

void Player::PlaceShips()
{
	int start_X;
	int start_Y;
	int direction;
	bool overlap = false;

	direction = rand() % 2;
	start_X = rand() % (8 - direction * m_Aircraft.GetMaxHP() + 1);
	start_Y = rand() % (8 - ((direction + 1) % 2) * m_Aircraft.GetMaxHP() + 1);

	for (int i = 0; i < m_Aircraft.GetMaxHP(); i++)
	{
		m_Aircraft.AddPosition('a' + start_X + i * direction,
			'1' + start_Y + i * ((direction + 1) % 2));
	}
	
	do
	{
		overlap = false;
		direction = rand() % 2;
		start_X = rand() % (8 - direction * m_BattleShip.GetMaxHP() + 1);
		start_Y = rand() % (8 - ((direction + 1) % 2) * m_BattleShip.GetMaxHP() + 1);
		for (int i = 0; i < m_Aircraft.GetMaxHP(); i++)
		{
			if (m_Aircraft.CheckPosition('a' + start_X + i * direction,
				'1' + start_Y + i * ((direction + 1) % 2)))
			{
				overlap = true;
				break;
			}
		}
	} while (overlap);

	for (int i = 0; i < m_BattleShip.GetMaxHP(); i++)
	{
		m_BattleShip.AddPosition('a' + start_X + i * direction,
			'1' + start_Y + i * ((direction + 1) % 2));
	}

	do
	{
		overlap = false;
		direction = rand() % 2;
		start_X = rand() % (8 - direction * m_Cruiser.GetMaxHP() + 1);
		start_Y = rand() % (8 - ((direction + 1) % 2) * m_Cruiser.GetMaxHP() + 1);
		for (int i = 0; i < m_Aircraft.GetMaxHP(); i++)
		{
			if (m_Aircraft.CheckPosition('a' + start_X + i * direction,
				'1' + start_Y + i * ((direction + 1) % 2)))
			{
				overlap = true;
				break;
			}
			if (m_BattleShip.CheckPosition('a' + start_X + i * direction,
				'1' + start_Y + i * ((direction + 1) % 2)))
			{
				overlap = true;
				break;
			}
		}
	} while (overlap);

	for (int i = 0; i < m_Cruiser.GetMaxHP(); i++)
	{
		m_Cruiser.AddPosition('a' + start_X + i * direction,
			'1' + start_Y + i * ((direction + 1) % 2));
	}
}

void Player::PrintShips()
{
	m_Aircraft.PrintPositions();
	m_BattleShip.PrintPositions();
	m_Cruiser.PrintPositions();
	for (int i = 0; i < _countof(m_Destroyer); i++)
	{
		m_Destroyer[i].PrintPositions();
	}

}