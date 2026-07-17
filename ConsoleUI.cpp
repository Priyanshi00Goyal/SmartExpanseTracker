/*
-------------------------------------------------------
Project : Smart Expense Tracker
Version : v3.0
Author  : Priyanshi Goyal
Language: C++
-------------------------------------------------------
*/

#include "ConsoleUI.h"

#include <iostream>

using namespace std;

void ConsoleUI::reset()
{
    cout << "\033[0m";
}

void ConsoleUI::red()
{
    cout << "\033[31m";
}

void ConsoleUI::green()
{
    cout << "\033[32m";
}

void ConsoleUI::yellow()
{
    cout << "\033[33m";
}

void ConsoleUI::blue()
{
    cout << "\033[34m";
}

void ConsoleUI::magenta()
{
    cout << "\033[35m";
}

void ConsoleUI::cyan()
{
    cout << "\033[36m";
}

void ConsoleUI::success(string message)
{
    green();
    cout << message << endl;
    reset();
}

void ConsoleUI::error(string message)
{
    red();
    cout << message << endl;
    reset();
}

void ConsoleUI::warning(string message)
{
    yellow();
    cout << message << endl;
    reset();
}

void ConsoleUI::heading(string message)
{
    cyan();
    cout << message << endl;
    reset();
}
