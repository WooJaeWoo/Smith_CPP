// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.
//

#pragma once

#include "targetver.h"
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <list>
#include <time.h>
#include <vector>
#include <string>
#include <sstream>

// TODO: ���α׷��� �ʿ��� �߰� ����� ���⿡�� �����մϴ�.

#include "HeaderSet.h"

int GetMaxHP(ShipType type);
Colors GetForeColor(ShipType type);
Colors GetBackColor(ShipType type);
std::string GetShipChar(ShipType type);
