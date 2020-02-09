#pragma once
#include <exception>

class SmallHeightMapExcepion : public std::exception
{
public:
	const char* what() const throw()
	{
		return "Level height too small, or odd number.";
	}
};
