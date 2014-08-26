#pragma once

class GameSetting
{
public:
	GameSetting();
	~GameSetting();

	std::vector<int>	GetNumShip() { return m_NumShip; }
	int					GetNumShipType() { return m_ShipTypeCount; }
	void				SetNumShip(std::vector<int> numShip);
	PlayerType			GetPlayerType() { return m_PlayerType; }


private:
	PlayerType			m_PlayerType;
	int					m_ShipTypeCount;
	std::vector<int>	m_NumShip;
};

