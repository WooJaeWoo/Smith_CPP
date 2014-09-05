#pragma once
#include "HeaderSet.h"

class GameRenderer
{
public:
	GameRenderer();
	~GameRenderer();


	void					RenderPages(GameStatus gameStatus);
	void					SetSizeOfMap(int sizeOfMap) { m_SizeOfMap = sizeOfMap; }
	void					SetHitResult(HitResult hitResult) { m_HitResult = hitResult; }
	void					SetTurn(int turn) { m_turn = turn; }

private:
	void					RenderBattleship();
	void					RenderSetting();
	void					RenderGamePlay();
	void					RenderWin();
	void					RenderLose();
	void					RenderFiller(int consoleWidth, int titleWidth);
	
	int						m_SizeOfMap;
	void					RenderMap(int gotoX, int gotoY);

	HitResult				m_HitResult;
	int						m_turn;
	void					PrintResult();
	void					PrintTurn();

	void					SetConsoleSize(int width, int height);
	void					SetCursorPosition(int x, int y);
	void					SetColor(int fcolor, int bcolor);
	void					SetCursorAndColor(int x, int y, int fcolor, int bcolor);
};

