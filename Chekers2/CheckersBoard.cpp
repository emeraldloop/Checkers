#include "CheckersBoard.h"
#include "pch.h"

CheckersBoard::CheckersBoard()
{
	unsigned int size = 8;
	this->boardsize = size;
	cells = new CellType * [size];
	for (unsigned int i = 0; i < size; i++)
		cells[i] = new CellType[size];
	for (unsigned int i = 0; i < size; i++) {
		for (unsigned int j = 0; j < size; j++) {
			if (i % 2 == 1)
				if (j % 2 == 1) cells[i][j] = CellType_NotAvailable;
				else cells[i][j] = CellType_Available;
			else
				if (j % 2 == 1) cells[i][j] = CellType_Available;
				else cells[i][j] = CellType_NotAvailable;
			if (((i == 0) || (i == 2)) && (j == 0 || j == 2 || j == 4 || j == 6))
				cells[i][j] = CellType_Black;
			if ((i == 1) && (j == 1 || j == 3 || j == 5 || j == 7))
				cells[i][j] = CellType_Black;

			if (((i == 5) || (i == 7)) && (j == 1 || j == 3 || j == 5 || j == 7))
				cells[i][j] = CellType_White;
			if ((i == 6) && (j == 0 || j == 2 || j == 4 || j == 6))
				cells[i][j] = CellType_White;
		}
	}
}

CheckersBoard::~CheckersBoard()
{
	for (unsigned int i = 0; i < boardsize; i++)
		delete[]cells[i];
	delete[]cells;
}

void CheckersBoard::Show()
{

	setlocale(LC_ALL, ".866");
	cout << " ";
	for (unsigned int j = 0, b = 65; j < boardsize; j++)
	{
		cout << (char)b++;
	}
	cout << endl;

	for (unsigned int i = 0; i < boardsize; i++)
	{
		cout << boardsize - i;
		for (unsigned int j = 0; j < boardsize; j++)
		{
			switch (cells[7 - i][j])
			{
			case CellType_Available:
				cout << (char) 219;
				break;
			case CellType_NotAvailable:
				cout << (char) 176;
				break;
			case CellType_Black:
				cout << "B";
				break;
			case CellType_White:
				cout << "W";
				break;
			}
		}
		cout << endl;
	}
}

void CheckersBoard::SetCell(int xpos, int ypos, CellType ct)
{
	cells[ypos][xpos] = ct;
}

bool CheckersBoard::CheckLegal1(int xpos, int ypos)
{
	if ((xpos < 0) || (xpos > boardsize - 1) || (ypos < 0) || (ypos > boardsize - 1))
		return false;
	return (cells[ypos][xpos] == CellType_Available);
}
