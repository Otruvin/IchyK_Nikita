#pragma once
#include "ConsoleAdapter.h"
class PacMan
{
private:
	unsigned score;
	int health;
	int x;
	int y;
	int directionX;
	int directionY;

public:
	PacMan(int startX, int startY, int startHealth = 3, int startScore = 0);
	void curshHealth();
	void eatGhost();
	void move(int directionX, int directionY, char pacModel);
	bool checkDeath();
	void addHealth(int countHealth);
	void addToScore(int coins);
	unsigned getScore();
	int getHealth();
	void setX(int x);
	void setY(int y);
	int getX();
	int getY();
};

