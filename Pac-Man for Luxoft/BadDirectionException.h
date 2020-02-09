#pragma once
#include <exception>

class BadDirectionException : public std::exception
{
public:
	const char* what() const throw()
	{
		return "Bad direction.";
	}
};