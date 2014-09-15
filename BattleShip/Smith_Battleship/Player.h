#pragma once

class Ship;
class Map;

class Player
{
public:
	Player();
	~Player();

	void						InitializePlayer();
	void						ResetPlayer();
	void						DefaultPlayer();
	void						ClearPlayer();

	void						MakeMaps(int mapSize);
	int							GetPlayerID() { return m_PlayerID; }
	void						SetPlayerType(PlayerType playerType) { m_PlayerType = playerType; }
	PlayerType					GetPlayerType() { return m_PlayerType; }
	void						SetNumShip(std::vector<int> numShip) { m_NumShip = numShip; }
	void						MakeShips();
	
	void						SetShip(Position position, ShipType shipType);
	Position					RandomSetShip(ShipType shipType);
	void						RenderUpdateMyMapStatus(int gotoX, int gotoY);
	void						RenderUpdateEnemyMapStatus(int gotoX, int gotoY);
	void						RenderRemain();
	void						SetShipCoords();

	Coordinate					RandomAttack();
	Coordinate					AIAttack(HitResult hitResult);

	void						MarkOnEnemyMap(Coordinate shot, HitResult hitResult);
	HitResult					SendResult(Coordinate shot);
	bool						GameOverCheck(HitResult hitResult);

	bool						IsValidSet(Position position, ShipType shipType);

private:
	static int					m_IDSeed;
	int							m_PlayerID;
	PlayerType					m_PlayerType;
	Map*						m_MyMap;
	Map*						m_EnemyMap;
	std::vector<int>			m_NumShip;
	std::vector<Ship*>			m_ShipList;
	std::vector<Position>		m_ShipPositions;
};
