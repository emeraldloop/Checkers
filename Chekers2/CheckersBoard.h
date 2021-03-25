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
	void SetCell(int xpos1, int ypos1, int xpos2, int ypos2, CellType ct);
	bool CheckLegal1(int xpos, int ypos);
};

