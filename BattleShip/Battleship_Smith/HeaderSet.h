#pragma once

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
	UP,
	DOWN,
	LEFT,
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