#pragma once
#include "CellType.h"
class CheckersBoard
{
private:
	int boardsize;
	CellType** cells;
public:
	CheckersBoard();
	virtual ~CheckersBoard();
	void Show();
	int Rand(int min,int max);
	void SetCell(int xpos1, int ypos1, int xpos2, int ypos2, CellType ct);
	void SetCell2(CellType ct);
	bool CheckLegal1(int xpos1, int ypos1, int xpos2, int ypos2,CellType ct);
	bool CheckLegalEat4PC(int ipos, int jpos, CellType ct);
};

