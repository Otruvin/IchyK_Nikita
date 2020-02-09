#pragma once
#include "Constants.h"
#include "ConsoleAdapter.h"
#include "PacMan.h"
#include "Ghost.h"
#include <vector>
#include <memory>

class Game
{
private:
	int numberLevelStart;
	std::unique_ptr<PacMan> pacMan;
	void resetMap();
	int mapGame[Constants::MAP_HEIGHT][Constants::MAP_WIDTH];
	void loadMap();
	std::vector<std::unique_ptr<Ghost>> ghosts;
public:
	explicit Game(int numberLevelStart = 1);
	void startLevel();
	virtual ~Game();
};

