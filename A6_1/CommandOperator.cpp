#include "functions.hpp"

void Command_Operator(SystemController &engine)
{
	std::string command_line;

	while(getline(std::cin,command_line))
	{
		try
		{
			engine.Handle_Cmd(command_line);
		}
		catch(std::runtime_error &ex)
		{
			std::cerr << ex.what() << std::endl;
		}
	}

}