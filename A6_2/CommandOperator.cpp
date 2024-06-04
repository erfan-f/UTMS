#include "functions.hpp"

void Command_Operator(SystemController &engine)
{
	IOHandler io_hanler;
	std::string command_line;
	std::vector <std::string> response;

	
	while(io_hanler.get_Command_Line(command_line))
	{
		try
		{
			engine.Handle_Cmd(command_line,response);
		}
		catch(std::runtime_error &ex)
		{
			io_hanler.Print_Error(ex.what());
		}
		io_hanler.Print_Data(response);
		response.clear();
	}

}
