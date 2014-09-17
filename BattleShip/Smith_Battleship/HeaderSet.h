#pragma once

#define KEY_LEFT	75
#define KEY_RIGHT	77
#define KEY_UP		72
#define KEY_DOWN	80
#define ESC			27
#define SPACE		32
#define ENTER		13

#define SHIPTYPECOUNT 4
#define DEFAULT_SHIP_COUNT 5
#define DEFAULT_MAP_SIZE 8
#define FIRST_MAP_GOTOX 9
#define FIRST_MAP_GOTOY 11

enum GameStatus
{
	GAMESTART,
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
	SHIP_DESTROYER,
	ATTACKED_SHIP,
	ATTACKED_MISS,
};

enum HitResult
{
	WRONG,
	MISS,
	HIT,
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
	PLAYER,
	AI,
	NETWORK,
};

enum GamePlayType
{
	PVP_PLAY,
	AI_PLAY,
	NET_PLAY,
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