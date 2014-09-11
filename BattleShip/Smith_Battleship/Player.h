#pragma once

class Ship;
class Map;

class Player
{
public:
	Player();
	~Player();

	void				MakeMaps(int mapSize);
	void				SetPlayerType(PlayerType playerType) { m_PlayerType = playerType; }
	void				SetNumShip(std::vector<int> numShip) { m_NumShip = numShip; }
	void				MakeShips();
	
	void				SetShip(Position position, ShipType shipType);
	void				RandomSetShip(Ship& ship);
	void				RenderUpdateMapStatus(int gotoX, int gotoY);
	void				RenderRemain();

	Coordinate			Attack();
	Coordinate			RandomAttack();
	HitResult			SendResult(Coordinate shot);

	bool				AttackableCheck(Coordinate shot);
	bool				IsValidSet(Position position, ShipType shipType);

private:
	PlayerType			m_PlayerType;
	Map*				m_MyMap;
	Map*				m_EnemyMap;
	std::vector<int>	m_NumShip;
	std::vector<Ship*>	m_ShipList;
};
