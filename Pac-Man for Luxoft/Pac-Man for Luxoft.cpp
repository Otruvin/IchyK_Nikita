#include "ConsoleAdapter.h"
#include "Constants.h"
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Game.h"
#include "Maps.h"
#include <exception>

int main()
{
	ConsoleAdapter consoleAdapter;
	std::unique_ptr<ConsoleAdapter> adapter(new ConsoleAdapter());
	std::vector<std::string> menuElements = { "START GAMNE", "STATISTICS", "EXIT" };
	int pointer = 0;
	bool gameSelected = false;

	consoleAdapter.setWindowSize(Constants::WINDOW_WIDTH, Constants::WINDOW_HEIGHT);
	consoleAdapter.setWindowTitle();
	consoleAdapter.initMainMenu();
	consoleAdapter.setCursorVisability(false);
	
	
	while (true)
	{
		system("cls");
		consoleAdapter.initMainMenu();
		for ( size_t i = 0; i < menuElements.size(); ++i)
		{
			if (i == pointer)
			{
				std::cout << "> " << menuElements[i] << std::endl;
			}
			else
			{
				std::cout << menuElements[i] << std::endl;
			}
		}

		while (true)
		{
			if (GetAsyncKeyState(VK_UP) != 0)
			{
				
				pointer -= 1;
				if (pointer == -1)
				{
					pointer = menuElements.size() - 1;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)
			{
				pointer += 1;
				if (pointer == menuElements.size())
				{
					pointer = 0;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_RETURN))
			{
				if (pointer == 0)
				{
					system("cls");
					try
					{
						consoleAdapter.setWindowSize(Constants::WINDOW_WIDTH_FOR_GAME, Constants::WINDOW_HEIGHT_FOR_GAME);
						std::unique_ptr<Game> newGame(new Game());
						newGame->startLevel();
						consoleAdapter.setWindowSize(Constants::WINDOW_WIDTH, Constants::WINDOW_HEIGHT);
						break;
					}
					catch (const std::exception & e)
					{
						std::cout << e.what() << std::endl;
						gameSelected = true;
						break;
					}
					break;
					
				}
				else if (pointer == 1)
				{
					system("cls");
					gameSelected = true;
					std::cout << "I did not make it in time" << std::endl;
					Sleep(5000);
					break;
				}
				else if (pointer == 2)
				{
					exit(0);
				}
			}
		}
		
		Sleep(100);
	}
	return 0;
}

