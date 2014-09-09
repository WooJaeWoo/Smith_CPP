// stdafx.cpp : 표준 포함 파일만 들어 있는 소스 파일입니다.
// Smith_Battleship.pch는 미리 컴파일된 헤더가 됩니다.
// stdafx.obj에는 미리 컴파일된 형식 정보가 포함됩니다.

#include "stdafx.h"

// TODO: 필요한 추가 헤더는
// 이 파일이 아닌 STDAFX.H에서 참조합니다.

int GetMaxHP(ShipType type)
{
	int ret = 0;
	switch (type)
	{
	case AIRCRAFT:
		ret = 5;
		break;
	case BATTLESHIP:
		ret = 4;
		break;
	case CRUISER:
		ret = 3;
		break;
	case DESTROYER:
		ret = 2;
		break;
	}
	return ret;
}

Colors GetForeColor(ShipType type)
{
	Colors color = BLACK;
	switch (type)
	{
	case AIRCRAFT:
		color = LIGHT_GRAY;
		break;
	case BATTLESHIP:
		color = GRAY;
		break;
	case CRUISER:
		color = DARK_RED;
		break;
	case DESTROYER:
		color = BLACK;
		break;
	}
	return color;
}

Colors GetBackColor(ShipType type)
{
	Colors color = BLACK;
	switch (type)
	{
	case AIRCRAFT:
		color = RED;
		break;
	case BATTLESHIP:
		color = BLUE;
		break;
	case CRUISER:
		color = YELLOW;
		break;
	case DESTROYER:
		color = GREEN;
		break;
	}
	return color;
}
std::string GetShipChar(ShipType type)
{
	std::string shipChar = "";
	switch (type)
	{
	case AIRCRAFT:
		shipChar = "Ａ";
		break;
	case BATTLESHIP:
		shipChar = "Ｂ";
		break;
	case CRUISER:
		shipChar = "Ｃ";
		break;
	case DESTROYER:
		shipChar = "Ｄ";
		break;
	}
	return shipChar;
}