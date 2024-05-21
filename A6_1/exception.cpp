#include "exception.hpp"


MethodException::MethodException(std::string text)
:runtime_error(text)
{
	message = text;
}


CommandException::CommandException(std::string text)
:runtime_error(text)
{
	message = text;
}
