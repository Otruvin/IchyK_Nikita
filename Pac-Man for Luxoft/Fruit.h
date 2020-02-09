#pragma once
#include <string>
class Fruit
{
private:
	int coast;
	std::string name;
public:
	Fruit(int coast, std::string name) : coast(coast), name(name) {};
	void hide() const;
	void enable() const;
	virtual ~Fruit() {};
};

