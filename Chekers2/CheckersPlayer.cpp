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
	int row1, col1,row2,col2;// 1 - ввод шашки, которой будут ходить 2 - ввод клетки куда шашка сходит
	cout << "Player " << name << ",your turn " << endl;
	cout << "Setting checker to move \nSet column  : ";
	cin >> row1;
	row1--;
	cout << "Set row: ";
	cin >> col1;
	col1--;
	
	cout << "Setting cell \nSet column  : ";
	cin >> row2;
	row2--;
	cout << "Set row: ";
	cin >> col2;
	col2--; 

	if (this->board->CheckLegal1(col1, row1, col2, row2,this->cellType))
	{
		this->board->SetCell(col1, row1, col2, row2, this->cellType);
		return true;
	}
	return false;
}

string CheckersPlayer::GetName()
{
	return this->name;
}
