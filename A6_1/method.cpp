#include "method.h"

Method::Method(std::string t , std::vector <std::string> cmds)
{
	type = t;
	commands = cmds;

}

bool Method::is_Equal(std::string m)
{
	if(type == m)
		return true;
	return false;
}

bool Method::is_Cmd_Valid(std::string cmd)
{
	for(int i=0 ; i<commands.size() ; i++)
	{
		if(cmd == commands[i])
			return true;
	}
	return false;
}




