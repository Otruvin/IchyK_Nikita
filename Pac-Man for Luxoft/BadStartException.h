#pragma once
#include <exception>

class BadStartException : public std::exception
{
public:
	const char * what() const throw()
	{
		return "Start level out of range.";
	}
};
