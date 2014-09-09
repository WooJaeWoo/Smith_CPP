// stdafx.cpp : ǥ�� ���� ���ϸ� ��� �ִ� �ҽ� �����Դϴ�.
// Smith_Battleship.pch�� �̸� �����ϵ� ����� �˴ϴ�.
// stdafx.obj���� �̸� �����ϵ� ���� ������ ���Ե˴ϴ�.

#include "stdafx.h"

// TODO: �ʿ��� �߰� �����
// �� ������ �ƴ� STDAFX.H���� �����մϴ�.

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
		shipChar = "��";
		break;
	case BATTLESHIP:
		shipChar = "��";
		break;
	case CRUISER:
		shipChar = "��";
		break;
	case DESTROYER:
		shipChar = "��";
		break;
	}
	return shipChar;
}