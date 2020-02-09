#pragma once
#include <memory>
#include "StateGhost.h"

class IGhost
{
protected:
	int x;
	int y;
	char model = char(219);
	int color;
	class StateGhost* stateGhost;
public:
	virtual void setState(StateGhost* stateGhost) = 0;
	virtual void spawn() = 0;
	virtual void move(const int& goalX, const int& goalY) = 0;
	virtual void connectPacMan() = 0;
	int getX() { return x; };
	int getY() { return y; };
	void setX(int x) { this->x = x; };
	void setY(int y) { this->y = y; };
	int getColor() { return this->color; };
	void setColor(int color) { this->color = color; };
	char getModel() { return model; };
	virtual ~IGhost() = default;
};

