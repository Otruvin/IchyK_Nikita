#include "Ghost.h"
#include "ConsoleAdapter.h"
#include <iostream>
#include "Constants.h"
#include "StateGhost.h"
#include <memory>

Ghost::Ghost(int startX, int startY, int color)
{
	this->x = startX;
	this->y = startY;
	this->color = color;
}

void Ghost::setState(StateGhost* stateGhost)
{
	this->stateGhost = stateGhost;
}

void Ghost::spawn()
{
	ConsoleAdapter::setCursorPosition(x, y);
	ConsoleAdapter::setTextColor(color);
	std::cout << model;
	ConsoleAdapter::setTextColor(Constants::COLOR_TEXT);
}

void Ghost::move(const int& goalX, const int& goalY)
{
	stateGhost->move(goalX, goalY, this);
}

void Ghost::connectPacMan()
{
	stateGhost->connectPacMan();
}


Ghost::~Ghost()
{
}


