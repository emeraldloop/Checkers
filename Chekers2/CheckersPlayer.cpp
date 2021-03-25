#include "CheckersPlayer.h"

CheckersPlayer::CheckersPlayer()
{
}

CheckersPlayer::~CheckersPlayer()
{
}

void CheckersPlayer::SetupPlayer(string name, CellType cellType)
{
	this->name = name;
	this->cellType = cellType;
}

void CheckersPlayer::SetBoard(CheckersBoard* board)
{
	this->board = board;
}

bool CheckersPlayer::MakeMove()
{
	unsigned int row, col;
	cout << "Player " << name << ",your turn " << endl;
	cout << "Set column: ";
	cin >> row;
	row--;
	cout << "Set row: ";
	cin >> col;
	col--;

	if (this->board->CheckLegal1(col, row))
	{
		this->board->SetCell(col, row, this->cellType);
		return true;
	}
	return false;
}

string CheckersPlayer::GetName()
{
	return this->name;
}
