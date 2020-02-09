#include "Game.h"
#include "Constants.h"
#include "BadStartException.h"
#include "SmallHeightMapException.h"
#include <memory>
#include <iostream>
#include <typeinfo>
#include "Ghost.h"
#include "StateNormalGhost.h"
#include "StateScaryGhost.h"

void Game::resetMap()
{
	for (int i = 0; i < Constants::MAP_HEIGHT; ++i)
	{
		for (int j = 0; j < Constants::MAP_WIDTH; ++j)
		{
			mapGame[i][j] = Constants::MAP1[i][j];
		}
	}
}

void Game::loadMap()
{
	
	for (int i = 0; i < Constants::MAP_HEIGHT; ++i)
	{
		for (int j = 0; j < Constants::MAP_WIDTH; ++j)
		{
			switch (Constants::MAP1[i][j])
			{
			case 0:
				ConsoleAdapter::setCursorPosition(j, i);
				ConsoleAdapter::setTextColor(Constants::COLOR_TABLETS);
				std::cout << char(249);
				ConsoleAdapter::setTextColor(Constants::COLOR_TEXT);
				break;
			case 1:
				ConsoleAdapter::setCursorPosition(j, i);
				std::cout << char(186);
				break;
			case 2:

				ConsoleAdapter::setCursorPosition(j, i);
				ConsoleAdapter::setTextColor(Constants::COLOR_TABLETS);
				std::cout << char(248);
				ConsoleAdapter::setTextColor(Constants::COLOR_TEXT);
				break;
			case 3:
				ConsoleAdapter::setCursorPosition(j, i);
				std::cout << " ";
				break;
			case 4:
				ConsoleAdapter::setCursorPosition(j, i);
				std::cout << char(196);
				break;
			case 5:
				ConsoleAdapter::setCursorPosition(j, i);
				std::cout << char(201);
				break;
			case 6:
				ConsoleAdapter::setCursorPosition(j, i);
				std::cout << char(187);
				break;
			case 7:
				ConsoleAdapter::setCursorPosition(j, i);
				std::cout << char(188);
				break;
			case 8:
				ConsoleAdapter::setCursorPosition(j, i);
				std::cout << char(200);
				break;
			case 9:
				ConsoleAdapter::setCursorPosition(j, i);
				std::cout << char(205);
				break;
			case 10:
				ConsoleAdapter::setCursorPosition(j, i);
				std::cout << char(176);
				break;
			case 11:
				ConsoleAdapter::setCursorPosition(j, i);
				std::cout << char(203);
				break;
			case 12:
				ConsoleAdapter::setCursorPosition(j, i);
				std::cout << char(175);
				break;
			case 13:
				ConsoleAdapter::setCursorPosition(j, i);
				std::cout << char(185);
				break;
			case 14:
				ConsoleAdapter::setCursorPosition(j, i);
				std::cout << char(204);
				break;
			case 15:
				ConsoleAdapter::setCursorPosition(j, i); 
				std::cout << " ";
				break;
			case 16:
				ConsoleAdapter::setCursorPosition(j, i);
				std::cout << " ";
				break;
			default:
				break;
			}
		}
	}

	ConsoleAdapter::setCursorPosition(-2, Constants::MAP_HEIGHT + 2);
	std::cout << "---------------------------------------------------" << std::endl;
	std::cout << "| Press Esc to return to main menu. Space - pause |" << std::endl;
	std::cout << "---------------------------------------------------" << std::endl;

	ConsoleAdapter::setCursorPosition(Constants::MAP_WIDTH + 3, 0);
	std::cout << "Score" << std::endl;
	ConsoleAdapter::setCursorPosition(Constants::MAP_WIDTH + 3, 3);
	std::cout << "Health" << std::endl;
	ConsoleAdapter::setCursorPosition(Constants::MAP_WIDTH + 3, 6);
	std::cout << "Level" << std::endl;
	ConsoleAdapter::setCursorPosition(Constants::MAP_WIDTH + 3, 7);
	std::cout << numberLevelStart + 1 << std::endl;
}

Game::Game(int numberLevelStart)
{
	if (numberLevelStart > Constants::NUM_LEVELS || numberLevelStart <= 0)
	{
		throw BadStartException();
	}
	else
	{
		pacMan = std::unique_ptr<PacMan>(new PacMan(13, 23));
		numberLevelStart = numberLevelStart - 1;
		ghosts.push_back(std::make_unique<Ghost>(13, 11, Constants::COLOR_BLINKY));
		ghosts.push_back(std::make_unique<Ghost>(11, 14, Constants::COLOR_PINKY));
		ghosts.push_back(std::make_unique<Ghost>(13, 14, Constants::COLOR_INKY));
		ghosts.push_back(std::make_unique<Ghost>(15, 14, Constants::COLOR_CLYDE));
		resetMap();
	}
	
}

void Game::startLevel()
{
	int tempDirectionX = 0;
	int tempDirectionY = 0;
	int numCoins = 0;
	int numTablets = 0;
	int tempPositionValue = 0;
	char tempPacManType = '<';

	loadMap();

	for (auto& ghost : ghosts)
	{
		ghost->spawn();
	}

	StateNormalGhost* normal = new StateNormalGhost();
	ghosts.at(0)->setState(normal);
	while (true)
	{
		//std::unique_ptr<StateNormalGhost> normal(new StateNormalGhost());
		
		
		ghosts.at(0)->move(pacMan->getX(), pacMan->getY());
		if (GetAsyncKeyState(VK_RIGHT) != 0)
		{
		
			tempPacManType = '<';
			tempDirectionX = 1;
			tempDirectionY = 0;
		}
		else if (GetAsyncKeyState(VK_LEFT) != 0)
		{
			tempPacManType = '>';
			tempDirectionX = -1;
			tempDirectionY = 0;


		}
		else if (GetAsyncKeyState(VK_UP) != 0)
		{

			tempPacManType = 'v';
			tempDirectionX = 0;
			tempDirectionY = -1;


		}
		else if (GetAsyncKeyState(VK_DOWN) != 0)
		{
			tempPacManType = '^';
			tempDirectionX = 0;
			tempDirectionY = 1;
		}
		else if (GetAsyncKeyState(VK_ESCAPE) != 0)
		{
			break;
		}
		else if (GetAsyncKeyState(VK_RETURN) != 0)
		{
			tempDirectionX = 0;
			tempDirectionY = 0;
		}
		else if (GetAsyncKeyState(VK_SPACE) != 0)
		{
			ConsoleAdapter::setCursorPosition(-2, Constants::MAP_HEIGHT + 1);
			system("pause"); 
			ConsoleAdapter::setCursorPosition(-2, Constants::MAP_HEIGHT + 1);
			std::cout << "                                                 ";
		}
		
		try
		{
			
			tempPositionValue = mapGame[pacMan->getY() + tempDirectionY][pacMan->getX() + tempDirectionX];
			
			switch (tempPositionValue)
			{
			case 0:
				pacMan->addToScore(100);
				mapGame[pacMan->getY() + tempDirectionY][pacMan->getX() + tempDirectionX] = 3;
				pacMan->move(tempDirectionX, tempDirectionY, tempPacManType);
				numCoins += 1;
				break;
			case 2:
				pacMan->addToScore(200);
				mapGame[pacMan->getY() + tempDirectionY][pacMan->getX() + tempDirectionX] = 3;
				pacMan->move(tempDirectionX, tempDirectionY, tempPacManType);
				numTablets += 1;
				
				break;
			case 3:
				pacMan->move(tempDirectionX, tempDirectionY, tempPacManType);
				break;
			case 15:
				pacMan->setX(0);
				pacMan->move(tempDirectionX, tempDirectionY, tempPacManType);
				ConsoleAdapter::setCursorPosition(Constants::MAP_WIDTH - 2, pacMan->getY());
				std::cout << " ";
				break;
			case 16:
				pacMan->setX(Constants::MAP_WIDTH);
				pacMan->move(tempDirectionX, tempDirectionY, tempPacManType);
				ConsoleAdapter::setCursorPosition(1, pacMan->getY());
				std::cout << " ";
				break;
			default:
				break;
			}

		}
		catch (const std::exception & e)
		{
			std::cout << e.what() << std::endl;
			break;
		}

		if (numCoins == 242 && numTablets == 4 && numberLevelStart < 256)
		{
			system("cls");
			numberLevelStart += 1;
			numCoins = 0;
			numTablets = 0;
			resetMap();
			pacMan->setX(13);
			pacMan->setY(23);
			ConsoleAdapter::setCursorPosition(10, 7);
			std::cout << "--------------------" << std::endl;
			ConsoleAdapter::setCursorPosition(10, 8);
			std::cout << "| Starting level " << numberLevelStart << " | " << std::endl;
			ConsoleAdapter::setCursorPosition(10, 9);
			std::cout << "--------------------" << std::endl;
			Sleep(1000);
			system("cls");
			pacMan->move(0, 0, '<');
			loadMap();
		}

		ConsoleAdapter::setCursorPosition(Constants::MAP_WIDTH + 3, 1);
		std::cout << "                 ";
		ConsoleAdapter::setCursorPosition(Constants::MAP_WIDTH + 3, 1);
		std::cout << pacMan->getScore();

		ConsoleAdapter::setCursorPosition(Constants::MAP_WIDTH + 3, 4);
		std::cout << "                 ";
		ConsoleAdapter::setCursorPosition(Constants::MAP_WIDTH + 3, 4);
		std::cout << pacMan->getHealth();

		
		Sleep(100);

	}

	delete normal;

}


Game::~Game()
{
	
}
