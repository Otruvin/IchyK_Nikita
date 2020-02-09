#pragma once
#include "StateGhost.h"
#include "Ghost.h"
#include "StrategyGhostsMovement.h"
#include <vector>
#include <memory>

class StateNormalGhost : public StateGhost
{
private:
	std::unique_ptr<StrategyGhostsMovement> strategy;
	bool checkWall(int x, int y);
public:
	void move(const int& goalX, const int& goalY, Ghost* ghost);
	void connectPacMan();
	virtual ~StateNormalGhost() = default;
};

