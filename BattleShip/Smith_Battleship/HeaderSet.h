#pragma once

#define KEY_LEFT	75
#define KEY_RIGHT	77
#define KEY_UP		72
#define KEY_DOWN	80
#define ESC			27
#define SPACE		32
#define ENTER		13

#define SHIPTYPECOUNT 4

enum GameStatus
{
	TITLE,
	SELECT_PLAYER,
	SELECT_MAP_SHIP,
	SET_SHIP,
	GAMEPLAY,
	WIN,
	LOSE,
};

enum Direction
{
	DOWN,
	RIGHT,
	UP,
	LEFT,
};

struct Coordinate
{
	int m_X;
	int m_Y;
};

struct Position
{
	int m_X;
	int m_Y;
	Direction m_direction;
};

enum MapStatus
{
	NOTHING,
	SHIP_AIRCRAFT,
	SHIP_BATTLESHIP,
	SHIP_CRUISER,
	SHEP_DESTROYER,
	ATTACKED_SHIP,
	ATTACKED_MISS,
};

enum HitResult
{
	HIT,
	MISS,
	DESTROY_AIRCRAFT,
	DESTROY_BATTLESHIP,
	DESTROY_CRUISER,
	DESTROY_DESTROYER,
};

enum ShipType
{
	AIRCRAFT,
	BATTLESHIP,
	CRUISER,
	DESTROYER,
};

enum PlayerType
{
	NONE,
	PVP,
	AI,
	NETWORK,
};

enum Colors
{
	BLACK,
	DARK_BLUE,
	DARK_GREEN,
	DARK_SKY,
	DARK_RED,
	DARK_PINK,
	DARK_YELLOW,
	LIGHT_GRAY,
	GRAY,
	BLUE,
	GREEN,
	SKY,
	RED,
	PINK,
	YELLOW,
	WHITE,
};