// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 및 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
//

#pragma once

#ifdef _DEBUG
#pragma comment(lib, "BGNL_debug.lib") //Network Library For Debug Mode
#else
#pragma comment(lib, "BGNL.lib") //Network Library For Release Mode
#endif

#include "Network.h"
#include "targetver.h"
#include "ShipData.h"

#include <stdio.h>
#include <tchar.h>

// TODO: 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.
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

void SetCursorPosition(int x, int y);
void SetColor(int fcolor, int bcolor);
void SetCursorAndColor(int x, int y, int fcolor, int bcolor);
