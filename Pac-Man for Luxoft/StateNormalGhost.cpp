#include "StateNormalGhost.h"
#include "Ghost.h"
#include "StrategyGhostsMovement.h"
#include "ConsoleAdapter.h"
#include "Constants.h"
#include <utility>
#include <iostream>
#include <vector>
#include <memory>
#include "Node.h"
#include <set>
#include <thread>

struct Step {
	int stepsCount;
	int x;
	int y;
	int back;
};

struct TempPoint {
	int x;
	int y;
};

bool StateNormalGhost::checkWall(int x, int y)
{
	return Constants::MAP1[y][x] == 0 || Constants::MAP1[y][x] == 3 || Constants::MAP1[y][x] == 4;
}

void StateNormalGhost::move(const int& goalX, const int& goalY, Ghost* ghost)
{
	int tempFinalX = goalX;
	int tempFinalY = goalY;
	int tempCurrentX = ghost->getX();
	int tempCurrentY = ghost->getY();

	//while (tempCurrentX != tempFinalX && tempCurrentY != tempFinalY)
	//{

		if (!checkWall(tempCurrentX + 1, tempCurrentY) || !checkWall(tempCurrentX - 1, tempCurrentY))
		{
			if (tempCurrentY > tempFinalY)
			{
				tempCurrentY -= 1;
			}
			else if (tempCurrentY < tempFinalY)
			{
				tempCurrentY += 1;
			}
		}
		else if (!checkWall(tempCurrentX, tempCurrentY + 1) || !checkWall(tempCurrentX, tempCurrentY - 1))
		{
			if (tempCurrentX > tempFinalX)
			{
				tempCurrentX -= 1;
			}
			else if (tempCurrentX < tempFinalX)
			{
				tempCurrentX += 1;
			}
		}
		else if (checkWall(tempCurrentX + 1, tempCurrentY) && checkWall(tempCurrentX - 1, tempCurrentY) && checkWall(tempCurrentX - 1, tempCurrentY) && checkWall(tempCurrentX, tempCurrentY + 1))
		{
			if (rand() < 0.2)
			{
				tempCurrentX -= 1;
			}
			else if (0.2 < rand() < 0.5)
			{
				tempCurrentY += 1;
			}
			else if (0.5 < rand() < 0.7)
			{
				tempCurrentY -= 1;
			}
			else if (0.7 < rand() < 1)
			{
				tempCurrentX += 1;
			}
		}
		else if (!checkWall(tempCurrentX, tempCurrentY - 1) || !checkWall(tempCurrentX, tempCurrentY + 1) && tempCurrentY > tempFinalY || tempCurrentY < tempFinalY && tempCurrentX == tempCurrentX)
		{
			if (rand() < 0.2)
			{
				tempCurrentX -= 1;
			}
			else
			{
				tempCurrentX += 1;
			}

		}
		else if (!checkWall(tempCurrentX + 1, tempCurrentY) || !checkWall(tempCurrentX - 1, tempCurrentY) && tempCurrentX > tempFinalX || tempCurrentX > tempFinalX && tempCurrentX == tempCurrentX)
		{
			if (rand() < 0.2)
			{
				tempCurrentY -= 1;
			}
			else
			{
				tempCurrentY += 1;
			}
		}
		else if (checkWall(tempCurrentX, tempCurrentY - 1) || checkWall(tempCurrentX, tempCurrentY + 1) && tempCurrentY > tempFinalY || tempCurrentY < tempFinalY && tempCurrentX == tempCurrentX)
		{

			
			if (rand() < 0.2)
			{
				tempCurrentY -= 1;
			}
			else
			{
				tempCurrentY += 1;
			}

		}
		else if (checkWall(tempCurrentX + 1, tempCurrentY) || checkWall(tempCurrentX - 1, tempCurrentY) && tempCurrentX > tempFinalX && tempCurrentX < tempFinalX || tempCurrentX == tempCurrentX)
		{
			if (rand() < 0.2)
			{
				tempCurrentX -= 1;
			}
			else
			{
				tempCurrentY += 1;
			}
		}
		


		int oldX = ghost->getX();
		int oldY = ghost->getY();

		ghost->setX(tempCurrentX);
		ghost->setY(tempCurrentY);

		if (Constants::MAP1[ghost->getY()][ghost->getX()] == 0)
		{
			ConsoleAdapter::setCursorPosition(ghost->getX(), ghost->getY());
			ConsoleAdapter::setTextColor(ghost->getColor());
			std::cout << ghost->getModel();
			ConsoleAdapter::setTextColor(Constants::COLOR_TABLETS);
			ConsoleAdapter::setCursorPosition(oldX, oldY);
			if (oldX != ghost->getX() || oldY != ghost->getY())
			{
				std::cout << char(249);
			}
			ConsoleAdapter::setTextColor(Constants::COLOR_TEXT);
		}
		else if (Constants::MAP1[ghost->getY()][ghost->getX()] == 3)
		{
			ConsoleAdapter::setCursorPosition(ghost->getX(), ghost->getY());
			ConsoleAdapter::setTextColor(ghost->getColor());
			std::cout << ghost->getModel();
			ConsoleAdapter::setTextColor(Constants::COLOR_TEXT);
			ConsoleAdapter::setCursorPosition(oldX, oldY);
			if (oldX != ghost->getX() || oldY != ghost->getY())
			{
				std::cout << " ";
			}
		}
		else if (Constants::MAP1[ghost->getY()][ghost->getX()] == 4)
		{
			ConsoleAdapter::setCursorPosition(ghost->getX(), ghost->getY());
			ConsoleAdapter::setTextColor(ghost->getColor());
			std::cout << ghost->getModel();
			ConsoleAdapter::setTextColor(Constants::COLOR_TEXT);
			ConsoleAdapter::setCursorPosition(oldX, oldY);
			if (oldX != ghost->getX() || oldY != ghost->getY())
			{
				std::cout << char(196);
			}
		}


}


void StateNormalGhost::connectPacMan()
{
}
