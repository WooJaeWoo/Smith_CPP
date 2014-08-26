#pragma once

#define KEY_LEFT	75
#define KEY_RIGHT	77
#define KEY_UP		72
#define KEY_DOWN	80
#define ESC			27
#define SPACE		32
#define ENTER		13

#define SHIPTYPECOUNT 4

struct Coordinate
{
	char m_X;
	char m_Y;
};

enum HitResult
{
	NOTHING,
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

enum Direction
{
	DOWN,
	LEFT,
	UP,
	RIGHT,
};

enum PlayerType
{
	NORMAL,
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