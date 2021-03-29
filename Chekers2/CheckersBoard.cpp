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
			if (((i == 0) || (i == 2)) && (j == 1 || j == 3 || j == 5 || j == 7)) // тут я задаю начальную расстановку
				cells[i][j] = CellType_Black;
			if ((i == 1) && (j == 0 || j == 2 || j == 4 || j == 6))
				cells[i][j] = CellType_Black;

			if (((i == 5) || (i == 7)) && (j == 0 || j == 2 || j == 4 || j == 6))
				cells[i][j] = CellType_White;
			if ((i == 6) && (j == 1 || j == 3 || j == 5 || j == 7))
				cells[i][j] = CellType_White;
		}
	}
}

CheckersBoard::~CheckersBoard()
{
	for ( int i = 0; i < boardsize; i++)
		delete[]cells[i];
	delete[]cells;
}

void CheckersBoard::Show()
{

	setlocale(LC_ALL, ".866");
	cout << " ";
	for ( int j = 0, b = 65; j < boardsize; j++)
	{
		cout << (char)b++;
	}
	cout << endl;

	for ( int i = 0; i < boardsize; i++)
	{
		cout << i+1;
		for ( int j = 0; j < boardsize; j++)
		{
			switch (cells[i][j])
			{
			case CellType_Available:
				cout << (char) 176;
				break;
			case CellType_NotAvailable:
				cout << (char) 219;
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

void CheckersBoard::SetCell(int xpos1, int ypos1, int xpos2, int ypos2, CellType ct)
{
	if ((xpos2 == xpos1 + 2) && (ypos2 == ypos1 + 2) && (cells[xpos1+1][ypos1+1]!=ct) && (cells[xpos1 + 1][ypos1 + 1] != CellType_Available) ) {

		cells[xpos1 + 1][ypos1 + 1] = CellType_Available;
	}
	
	if ((xpos2 == xpos1 + 2) && (ypos2 == ypos1 - 2) && (cells[xpos1 + 1][ypos1 - 1] != ct) && (cells[xpos1 + 1][ypos1 - 1] != CellType_Available)) {

		cells[xpos1 + 1][ypos1 - 1] = CellType_Available;
	}
	if ((xpos2 == xpos1 - 2) && (ypos2 == ypos1 - 2) && (cells[xpos1 - 1][ypos1 - 1] != ct) && (cells[xpos1 - 1][ypos1 - 1] != CellType_Available)) {

		cells[xpos1 - 1][ypos1 - 1] = CellType_Available;
	}

	if ((xpos2 == xpos1 - 2) && (ypos2 == ypos1 + 2) && (cells[xpos1 - 1][ypos1 + 1] != ct) && (cells[xpos1 - 1][ypos1 + 1] != CellType_Available)) {

		cells[xpos1 - 1][ypos1 + 1] = CellType_Available;
	}
	
	cells[xpos1][ypos1] = CellType_Available;
	cells[xpos2][ypos2] = ct; 
}

bool CheckersBoard::CheckLegal1(int xpos1, int ypos1, int xpos2, int ypos2,CellType ct)
{
	if ((xpos1 < 0) || (xpos1 > boardsize - 1) || (ypos1 < 0) || (ypos1 > boardsize - 1)) // ограничения доски
		return false;
	if ((xpos2 < 0) || (xpos2 > boardsize - 1) || (ypos2 < 0) || (ypos2 > boardsize - 1))
		return false;
	if ((cells[xpos1][ypos1] != ct) || (cells[xpos2][ypos2] !=CellType_Available)) // выбрана шашка не того игрока или ход в недоступную клетку
		return false;

	if ((cells[xpos1 + 1][ypos1 + 1] != ct) && (cells[xpos1 + 1][ypos1 + 1] != CellType_Available) && (xpos2 == xpos1 + 2) && (ypos2 == ypos1 + 2)  ) //если "наискасок" есть вражеская шашка - её можно съесть 
		return true;
	if ((cells[xpos1 + 1][ypos1 - 1] != ct) && (cells[xpos1 + 1][ypos1 - 1] != CellType_Available) && (xpos2 == xpos1 + 2) && (ypos2 == ypos1 - 2))
		return true;
	if ((cells[xpos1 - 1][ypos1 - 1] != ct) && (cells[xpos1 - 1][ypos1 - 1] != CellType_Available) && (xpos2 == xpos1 - 2) && (ypos2 == ypos1 - 2))
		return true;
	if ((cells[xpos1 - 1][ypos1 + 1] != ct) && (cells[xpos1 - 1][ypos1 + 1] != CellType_Available) && (xpos2 == xpos1 - 2) && (ypos2 == ypos1 + 2))
		return true;



	if ((xpos2 > xpos1 + 1) && (xpos2 < xpos1 - 1) && (ypos2 > ypos1 + 1) && (ypos2 < ypos1 - 1)) // движение не дальше чем на +1
		return false;
	


	

	return true;
}
