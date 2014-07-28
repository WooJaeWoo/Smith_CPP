#pragma once

enum DIRECTION {VERTICAL, HORIZONTAL};

class Ship
{
public:
	Ship();
	~Ship();

	int GetHP() { return hp; }; //간단하고 가벼운 함수를 인라인으로 넣어용~!
	HitResult HitCheck(Position hitPos);
	void Render();

private:
	int hp;
	int length;
	DIRECTION direction;
	int startX;
	int startY;
};