#include "pch.h"
#include <iostream>
#include "CheckersBoard.h"
int main()
{
    CheckersBoard* board;
    board = new CheckersBoard();
    board->Show();
    _getch();
    delete board;
}

