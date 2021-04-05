#include "CheckersBoard.h"
#include "pch.h"
#include <ctime>
CheckersBoard::CheckersBoard()
{
	int size = 8;
	this->boardsize = size;
	cells = new CellType * [size];
	for ( int i = 0; i < size; i++)
		cells[i] = new CellType[size];
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
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

int CheckersBoard::Rand(int min,int max)
{	
	srand(time(NULL));

	return rand() % (max - min + 1) + min;
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

void CheckersBoard::SetCell2(CellType ct)
{
	int size = 8;
	int i, j, k, n, randnumb,randnumb2, ipos2, jpos2;
	k = 0;
	bool k2=false;
	bool m = false;
	n = 0;

	for ( i = 0; i < size; i++) {           //подсчёт белых шашек способных сходить
		for ( j = 0; j < size; j++) {
			while ((cells[i][j] == CellType_White)) {
				if ((j!=size-1) && (i!=size-1) && (cells[i + 1][j + 1] == CellType_Available)) {
					n++;
					break;
				}
				if ((j != 0) && (i != size-1) && (cells[i + 1][j - 1] == CellType_Available)) {
					n++;
					break;
				}
				if ((j != 0) && (i != 0) && (cells[i - 1][j - 1] == CellType_Available)) {
					n++;
					break;
				}
				if ((j != size-1) && (i!=0) && (cells[i - 1][j + 1] == CellType_Available)) { 
					n++;
					break;
				}
				break;

			}
		}
	}
	
	cout << "\n n shashek" << n << "\n";
	randnumb = Rand(1, n);
	n = 0;
	cout << "rand n -" << randnumb << "\n";
	
		for (i = 0; i < size; i++) {           //идём до шашки выбранной случайно
			for (j = 0; j < size; j++) {
				while ((cells[i][j] == CellType_White)) {
					if ((j != size - 1) && (i != size - 1) && (cells[i + 1][j + 1] == CellType_Available)) {
						n++;
						break;
					}
					if ((j != 0) && (i != size - 1) && (cells[i + 1][j - 1] == CellType_Available)) {
						n++;
						break;
					}
					if ((j != 0) && (i != 0) && (cells[i - 1][j - 1] == CellType_Available)) {
						n++;
						break;
					}
					if ((j != size - 1) && (i != 0) && (cells[i - 1][j + 1] == CellType_Available)) {
						n++;
						break;
					}
					break;
				}
				if ((n == randnumb) && (CheckLegalEat4PC(i, j, CellType_White) == false)) { //считаем способы, которыми может сходить шашка (1 или 2)

					while ((cells[i][j] == CellType_White)) {
						if ((j != 0) && (i != 0) && (cells[i - 1][j - 1] == CellType_Available)) {
							k++;
							m = true;
						}
						if ((j != size - 1) && (i != 0) && (cells[i - 1][j + 1] == CellType_Available)) {
							k++;
							m = false;
						}

						if (k < 2) {
							switch (m) {
							case true:
								ipos2 = i - 1;
								jpos2 = j - 1;
								k2 = true;
								break;
							case false:
								ipos2 = i - 1;
								jpos2 = j + 1;
								k2 = true;
								break;

							}
						}
						if (k == 2) {
							randnumb2 = Rand(1, k);// присваимваем randnumb2 значение варианта хода шашки
							switch (randnumb2) {
							case 1:
								ipos2 = i - 1;
								jpos2 = j - 1;
								k2 = true;
								break;
							case 2:
								ipos2 = i - 1;
								jpos2 = j + 1;
								k2 = true;
								break;

							}

						}
						break;
					}


				}



				if (k2 == true) {
					cells[i][j] = CellType_Available;
					cells[ipos2][jpos2] = CellType_White;
					break;
				}
			}
			if (k2 == true) break;
		}
	









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

bool CheckersBoard::CheckLegalEat4PC(int i, int j, CellType ct)
{
	int  randnumb,n=0;//n-количество рабочих вариантов "съедания" вокруг шашки
	int size = 8;
	int k = 0;

	
		
	int* p_arr = new int[4];// 4 - число вариантов "съеданий"(наискасок в 4(или более если будет дамка) стороны),
							// сам массив нужен нам для обозначения возможности съесть именно этим способом: 0 - способ съесть не работает 1 - работает
			
	for (int x = 0; x < 4; x++) {//заполняем массив и считаем сколькими способами может сходить шашка
				switch (x)
				{
				case 0:
					if ((j < size - 2) && (i < size - 2) && (cells[i + 1][j + 1] != ct) && (cells[i + 1][j + 1] != CellType_Available) && (cells[i + 2][j + 2] == CellType_Available)) { //1способ
						p_arr[x] = 1;
						n++;
					}
					else
						p_arr[x] = 0;
					break;
				case 1:
					if ((j > 1) && (i != size - 2) && (cells[i + 1][j - 1] != ct) && (cells[i + 1][j - 1] !=CellType_Available) && (cells[i + 2][j - 2] == CellType_Available)) { //2
						p_arr[x] = 1;
						n++;
					}
					else
						p_arr[x] = 0;
					break;
				case 2:
					if ((j > 1) && (i > 1) && (cells[i - 1][j - 1] != ct) && (cells[i - 1][j - 1] != CellType_Available) && (cells[i - 2][j - 2] == CellType_Available)) { //3
						p_arr[x] = 1;
						n++;
					}
					else
						p_arr[x] = 0;
					break;
				case 3:
					if ((j < size - 2) && (i > 1) && (cells[i - 1][j + 1] != ct) && (cells[i - 1][j + 1] != CellType_Available) && (cells[i - 2][j + 2] == CellType_Available)) { //4
						p_arr[x] = 1;
						n++;
					}
					else
						p_arr[x] = 0;
					break;
				}
	}
	if (n > 0) {
		randnumb = Rand(1, n);//выбираем случайный ход из возможных(!) ходов и присваиваем это значение randnumb

		for (int x = 0; x < 4; x++) { //проходим "массив способов съесть" и если это "рабочий" способ, то мы увеличиваем счётчик k, если счётчик будет равен номеру случайного способа сходить(randnumb),
									  //тогда в зависимости от номера варианта x - делаем нужный ход
			if (p_arr[x] == 1)
				k++;
			if (k == randnumb)
			{
				switch (x) {
				case 0:
					cells[i][j] = CellType_Available;
					cells[i + 1][j + 1] = CellType_Available;
					cells[i + 2][j + 2] = ct;
					break;
				case 1:
					cells[i][j] = CellType_Available;
					cells[i + 1][j - 1] = CellType_Available;
					cells[i + 2][j - 2] = ct;
					break;
				case 2:
					cells[i][j] = CellType_Available;
					cells[i - 1][j - 1] = CellType_Available;
					cells[i - 2][j - 2] = ct;
					break;
				case 3:
					cells[i][j] = CellType_Available;
					cells[i - 1][j + 1] = CellType_Available;
					cells[i - 2][j + 2] = ct;
					break;
				}
				delete[] p_arr;
				return true;// возвращаем true, показывая этим что можно было съесть и ход уже совершен
			}

		}
	}
delete[] p_arr;
return false;
}
