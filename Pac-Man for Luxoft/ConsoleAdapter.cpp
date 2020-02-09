#include "ConsoleAdapter.h"
#include "Constants.h"
#include <iostream>
#include <Windows.h>

void ConsoleAdapter::setWindowSize(const int windowWidth, const int windowHeight)
{
	
	COORD coord;
	coord.X = windowWidth;
	coord.Y = windowHeight;

	SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Bottom = windowHeight - 1;
	Rect.Right = windowWidth - 1;

	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &Rect);

}

void ConsoleAdapter::setWindowTitle()
{
	SetConsoleTitle(L"Pac-man");
}

void ConsoleAdapter::setScreenColor(int color, const int windowWidth, const int windowHeight)
{
	COORD coord = { 0, 0 };
	DWORD dwWritten;
	FillConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color, windowWidth * windowHeight, coord, &dwWritten);
}

void ConsoleAdapter::setCursorPosition(int x, int y)
{
	COORD cursor = { x + 2 , y + 2 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}

void ConsoleAdapter::setTextColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void ConsoleAdapter::setCursorVisability(bool visible)
{
	CONSOLE_CURSOR_INFO cursor;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
	cursor.bVisible = visible;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

void ConsoleAdapter::initMainMenu()
{
	std::cout << "\n\n" << std::endl;
	std::cout << "\t\t\t\t______                    ___  ___              " << std::endl;
	std::cout << "\t\t\t\t| ___ \\                   |  \\/  |              " << std::endl;
	std::cout << "\t\t\t\t| |_/ /__ _   ___  ______ | .  . |  __ _  _ __  " << std::endl;
	std::cout << "\t\t\t\t|  __// _` | / __||______|| |\\/| | / _` || '_ \\ " << std::endl;
	std::cout << "\t\t\t\t| |  | (_| || (__         | |  | || (_| || | | |" << std::endl;
	std::cout << "\t\t\t\t\\_|   \\__,_| \\___|        \\_|  |_/ \\__,_||_| |_|" << std::endl;
	std::cout << "                                          \n" << std::endl;
	std::cout << "  -----------------------------------------" << std::endl;
	std::cout << "  |                      ^                |" << std::endl;
	std::cout << "  | To move use:   < -   |   - >          |" << std::endl;
	std::cout << "  | To escape press:    Esc  (in game)    |" << std::endl;
	std::cout << "  -----------------------------------------\n\n" << std::endl;
}

