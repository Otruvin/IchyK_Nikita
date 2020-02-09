#pragma once
#include <queue>
class StatisticsTable
{
private:
	std::queue<unsigned> statistics;
public:
	void readStatistics();
	std::queue<unsigned> getStatistics();
	void clearStatistics();
	static void updateStatistics();
};

