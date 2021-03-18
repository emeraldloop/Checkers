#pragma once
#include "pch.h"
#include "CheckersBoard.h"
class CheckersPlayer
{
private:
	CheckersBoard* board;
	CellType cellType;
	string name;
public:
	CheckersPlayer();
	virtual ~CheckersPlayer();
	void SetupPlayer(string name, CellType cellType);
	void SetBoard(CheckersBoard* board);
	bool MakeMove();
	string GetName();
};

