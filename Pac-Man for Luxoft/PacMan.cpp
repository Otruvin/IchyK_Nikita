#include "PacMan.h"
#include <iostream>
#include <Windows.h>
#include "BadDirectionException.h"
#include "Constants.h"

PacMan::PacMan(int startX, int startY, int startHealth, int startScore) : 
	x(startX),
	y(startY),
	health(startHealth),
	score(startScore)
{
	directionX = 0;
	directionY = 0;
}

void PacMan::curshHealth()
{
	health -= 1;
}

void PacMan::eatGhost()
{
	score += 400;
}

void PacMan::move(int directionX, int directionY, char pacModel = '<')
{

	int oldX;
	int oldY;

	if (directionX > 1 || directionX < -1 || directionY > 1 || directionY < -1)
	{
		throw BadDirectionException();
	}

	oldX = x;
	oldY = y;
	x += directionX;
	y += directionY;
	ConsoleAdapter::setCursorPosition(x, y);
	ConsoleAdapter::setTextColor(Constants::COLOR_TABLETS);
	std::cout << pacModel << std::endl;
	ConsoleAdapter::setTextColor(Constants::COLOR_TEXT);
	ConsoleAdapter::setCursorPosition(oldX, oldY);
	if (oldX != x || oldY != y)
	{
		std::cout << " ";
	}
	
}

bool PacMan::checkDeath()
{
	return health <= 0;
}

void PacMan::addHealth(int countHealth)
{
	health += countHealth;
}

void PacMan::addToScore(int coins)
{
	score += coins;
}

unsigned PacMan::getScore()
{
	return score;
}

int PacMan::getHealth()
{
	return health;
}

void PacMan::setX(int x)
{
	this->x = x;
}

void PacMan::setY(int y)
{
	this->y = y;
}

int PacMan::getX()
{
	return x;
}

int PacMan::getY()
{
	return y;
}



