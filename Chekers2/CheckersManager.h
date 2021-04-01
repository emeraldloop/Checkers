#pragma once
#include "CheckersBoard.h"
#include "CheckersPlayer.h"
#include "PCPlayer.h"
#include "pch.h"
class CheckersManager
{
private:
	CheckersBoard* board;
	CheckersPlayer* player1;
	CheckersPlayer* player2;
	PCplayer* player3;
	CheckersPlayer* currentPlayer;
	int* ptrII = new int;
public:
	CheckersManager();
	virtual ~CheckersManager();
	bool Init();
	void ShowBoard();
	void MakeMove();
};

