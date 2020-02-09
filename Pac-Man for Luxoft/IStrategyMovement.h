#pragma once
#include "Constants.h"
#include <utility>
#include <vector>
#include "Node.h"

class IStrategyMovement
{
public:
	virtual std::vector<Node> executeMove(const int & goalX, const int & goalY, int positionX, int positionY) = 0;
};