// StringLength.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
#include <string>

int _tmain(int argc, _TCHAR* argv[])
{
	char* txt2[] = { "Miss", "Hit", "Destroyed" };
	int txt2Length = sizeof(txt2)/sizeof(txt2[0]);
	std::string txt = "ABCD";
	int txtLength = txt.length();
	printf_s("%d\n", txtLength);
	printf_s("%d\n", txt2Length);
	return 0;
}

