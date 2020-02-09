#pragma once
#include "IStrategyMovement.h"
#include <utility>
#include <vector>
#include "Node.h"

class StrategyGhostsMovement : public IStrategyMovement
{
private:
	static int h(int x, int y, int x2, int y2);
	static bool checkWall(int x, int y);
public:
	StrategyGhostsMovement();
	static std::vector<Node> executeMove(const int & goalX, const int & goalY, int positionX, int positionY);
};

