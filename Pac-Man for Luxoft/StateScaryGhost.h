#pragma once
#include "StateGhost.h"

class StateScaryGhost : public StateGhost
{
public:
	void move(const int& goalX, const int& goalY);
	void connectPacMan();
};

