#pragma once
#include "IGhost.h"
#include "Ghost.h"

class StateGhost
{
protected:
	class Ghost* ghost;
public:
	virtual void move(const int& goalX, const int& goalY, Ghost* ghost) = 0;
	virtual void connectPacMan() = 0;
	virtual ~StateGhost() = default;
};