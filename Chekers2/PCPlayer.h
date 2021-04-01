#pragma once
#include "pch.h"
#include "CheckersBoard.h"
class PCplayer
{

private:
	CheckersBoard* board;
	CellType cellType;
	string name;
public:
	PCplayer();
	virtual ~PCplayer();
	void SetupPlayer(string name, CellType cellType);
	void SetBoard(CheckersBoard * board);
	bool MakeMove();
	string GetName();
	
};
