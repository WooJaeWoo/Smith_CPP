#pragma once

enum DIRECTION {VERTICAL, HORIZONTAL};

class Ship
{
public:
	Ship();
	~Ship();

	int GetHP() { return hp; }; //�����ϰ� ������ �Լ��� �ζ������� �־��~!
	bool HitCheck();
	void Render();

private:
	int hp;
	int length;
	DIRECTION direction;
	int startX;
	int startY;
};