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
	void SetCell(int xpos, int ypos, CellType ct);
};

