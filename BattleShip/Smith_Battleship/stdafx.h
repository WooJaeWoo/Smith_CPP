// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

// TODO: ���α׷��� �ʿ��� �߰� ����� ���⿡�� �����մϴ�.
#include <iostream>
#include <list>
#include <vector>
#include <conio.h>
#include <string>
#include <time.h>
#include <sstream>
#include <crtdbg.h>
#include <windows.h>
#include "HeaderSet.h"

#ifdef _DEBUG
#define new new(_CLIENT_BLOCK, __FILE__, __LINE__)
#endif

int GetMaxHP(ShipType stype);
Colors GetForeColor(ShipType type);
Colors GetBackColor(ShipType type);
std::string GetShipChar(ShipType type);