#include "StrategyGhostsMovement.h"
#include <algorithm>
#include "Constants.h"
#include <vector>
#include <iostream>
#include <utility>
#include <thread>
#include <set>
#include "Node.h"

int StrategyGhostsMovement::h(int x, int y, int x2, int y2)
{
	return abs(x - x2) + abs(y - y2);
}

bool StrategyGhostsMovement::checkWall(int x, int y)
{
	return Constants::MAP1[y][x] == 0 || Constants::MAP1[y][x] == 3 || Constants::MAP1[y][x] == 4;
}

StrategyGhostsMovement::StrategyGhostsMovement()
{
}

std::vector<Node> StrategyGhostsMovement::executeMove(const int & goalX, const int & goalY, int positionX, int positionY)
{

	auto sortNodes = [](const Node& n1, const Node& n2) -> bool
	{
		return n1.value < n2.value;
	};

	std::vector<Node> tempPath;

	std::thread first([&]() {
		if (checkWall(positionX + 1, positionY)) tempPath.push_back(Node(positionX + 1, positionY, h(goalX, goalY, positionX + 1, positionY)));
		});
	std::thread second([&]() {
		if (checkWall(positionX, positionY + 1)) tempPath.push_back(Node(positionX, positionY + 1, h(goalX, goalY, positionX, positionY + 1)));
		});
	std::thread third([&]() {
		if (checkWall(positionX, positionY - 1)) tempPath.push_back(Node(positionX, positionY - 1, h(goalX, goalY, positionX, positionY - 1)));
		});
	std::thread fourth([&]() {
		if (checkWall(positionX - 1, positionY)) tempPath.push_back(Node(positionX - 1, positionY, h(goalX, goalY, positionX - 1, positionY)));
		});

	first.join();
	second.join();
	third.join();
	fourth.join();

	std::sort(tempPath.begin(), tempPath.end(), sortNodes);


	return tempPath;
}

