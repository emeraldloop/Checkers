#include "CheckersManager.h"

CheckersManager::CheckersManager()
{
}

CheckersManager::~CheckersManager()
{
	delete this->player1;
	delete this->board;
	if (*ptrII == 1)
		delete this->player3;
	else delete this->player2;
	delete this->ptrII;
}

bool CheckersManager::Init()
{
	
	string playerName;
	cout << "Do you want to play with computer(1) or 1 on 1(2)? \n";
	cin >> *ptrII;
	this->board = new CheckersBoard;
	this->player1 = new CheckersPlayer();
	if (*ptrII == 2)
		this->player2 = new CheckersPlayer();
	else
		this->player3 = new PCplayer();
	cout << "Write black player's name ";
	cin >> playerName;
	player1->SetupPlayer(playerName, CellType_Black);
	cout << "Write white player's name ";
	cin >> playerName;
	if (*ptrII == 2)
		player2->SetupPlayer(playerName, CellType_White);
	else player3->SetupPlayer(playerName, CellType_White);
	player1->SetBoard(this->board);
	if (*ptrII == 2)
		player2->SetBoard(this->board);
	else player3->SetBoard(this->board);
	currentPlayer = player1;

	return true;
}

void CheckersManager::ShowBoard()
{
	this->board->Show();
}

void CheckersManager::MakeMove()
{
	int k = 0;


	if (*ptrII == 2) {
		ShowBoard();
		while (!currentPlayer->MakeMove())
		{
			cout << "Not available move, try again " << endl;
			ShowBoard();
		}

		currentPlayer = (currentPlayer == player1) ? player2 : player1;
	}
	if (*ptrII == 1) {
		ShowBoard();
		for (int i = 0; i < 100; i++) {
			if (k % 2 == 0) {
				player1->MakeMove();
				k++;
			}
			if (k % 2 != 0) {
				cout << "\n PC's move is...\n";
				player3->MakeMove();
				k++;
			}
			ShowBoard();
		}

	}
}
