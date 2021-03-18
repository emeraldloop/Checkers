#pragma once
#include "CheckersBoard.h"
#include "CheckersPlayer.h"
#include "pch.h"
class CheckersManager
{
private:
	CheckersBoard* board;
	CheckersPlayer* player1;
	CheckersPlayer* player2;
	CheckersPlayer* currentPlayer;
public:
	CheckersManager();
	virtual ~CheckersManager();
	bool Init();
	void ShowBoard();
	void MakeMove();
};

