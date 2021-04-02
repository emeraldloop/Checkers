
#include "PCplayer.h"

PCplayer::PCplayer()
{
}

PCplayer::~PCplayer()
{
}

void PCplayer::SetupPlayer(string name, CellType cellType)
{
	this->name = name;
	this->cellType = cellType;
}

void PCplayer::SetBoard(CheckersBoard* board)
{
	this->board = board;
}

bool PCplayer::MakeMove()
{
	this->board->SetCell2(this->cellType);
	return true;
}

string PCplayer::GetName()
{
	return string();
}
