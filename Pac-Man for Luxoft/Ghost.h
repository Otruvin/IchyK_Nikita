#pragma once
#include "IGhost.h"
#include "StateGhost.h"
#include <memory>

class Ghost : public IGhost
{
public:
	Ghost(int startX, int startY, int color);
	void setState(StateGhost* stateGhost);
	void spawn();
	void move(const int& goalX, const int& goalY);
	void connectPacMan();
	virtual ~Ghost();
};

