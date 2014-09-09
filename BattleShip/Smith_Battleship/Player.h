#pragma once

class Ship;
class Map;

class Player
{
public:
	Player();
	~Player();

	void				MakeMaps(int mapSize);
	Map*				GetMyMap() { return m_MyMap; }
	Map*				GetEnemyMap() { return m_EnemyMap; }
	void				SetPlayerType(PlayerType playerType) { m_PlayerType = playerType; }
	void				SetNumShip(std::vector<int> numShip) { m_NumShip = numShip; }
	void				MakeShips();
	
	void				SetShip(Ship& ship, Position position);
	void				RandomSetShip(Ship& ship);

	Coordinate			Attack();
	Coordinate			RandomAttack();
	HitResult			SendResult(Coordinate shot);

	bool				InvalidPosition(Ship& ship, Position position);
	bool				AttackableCheck(Coordinate shot);

private:
	PlayerType			m_PlayerType;
	Map*				m_MyMap;
	Map*				m_EnemyMap;
	std::vector<int>	m_NumShip;
	std::vector<Ship*>	m_ShipList;
};
