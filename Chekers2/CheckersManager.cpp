#include "CheckersManager.h"

CheckersManager::CheckersManager()
{
}

CheckersManager::~CheckersManager()
{
	delete this->player1;
	delete this->player2;
	delete this->board;
}

bool CheckersManager::Init()
{
	string playerName;
	this->board = new CheckersBoard;
	this->player1 = new CheckersPlayer();
	this->player2 = new CheckersPlayer();
	cout << "Write black player's name ";
	getline(cin, playerName);
	player1->SetupPlayer(playerName, CellType_Black);
	cout << "Write white player's name ";
	getline(cin, playerName);
	player2->SetupPlayer(playerName, CellType_White);
	player1->SetBoard(this->board);
	player2->SetBoard(this->board);
	currentPlayer = player1;

	return true;
}

void CheckersManager::ShowBoard()
{
	this->board->Show();
}

void CheckersManager::MakeMove()
{
	ShowBoard();
	while (!currentPlayer->MakeMove())
	{
		cout << "Not available move, try again " << endl;
		ShowBoard();
	}
	currentPlayer = (currentPlayer == player1) ? player2 : player1;
}
