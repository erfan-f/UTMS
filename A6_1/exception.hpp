#ifndef EXCEPTION
#define EXCEPTION

#include <stdexcept>
#include <string>

class MethodException : public std::runtime_error
{
public:
	MethodException(std::string text);
private:
	std::string message;
};


class CommandException : public std::runtime_error
{
	public:
		CommandException(std::string text);
	private:
		std::string message;
};

#endif