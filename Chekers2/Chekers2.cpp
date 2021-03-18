#include "pch.h"
#include <iostream>
#include "CheckersBoard.h"
#include "CheckersManager.h"
int main()
{
    CheckersManager manager;
    if (!manager.Init())
    {
        cout << "False data, exit...";
        _getch();
        return 0;
    }
    while (true)
    {
        manager.MakeMove();
    }
}

