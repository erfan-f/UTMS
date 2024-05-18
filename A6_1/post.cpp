#include "post.h"

Post::Post(std::string t , std::vector <std::string> cmds)
:Method(t,cmds){}


void Post::Process_Cmd(std::string cmd_line ,std::vector<Major*> &majors ,std::vector<Unit*> &units ,std::vector<User*> &users , User **current_user,bool &user_logged_in)
{
	std::stringstream S(cmd_line);

	std::string temp_str , command;

	S >> temp_str;
	S >> command;
	S >> temp_str;
	if(command == USER_CMD_TYPE_1)
	{
		std::string operator_id,id,operator_password,password;
		S >> operator_id;
		S >> id;
		S >> operator_password;
		S >> password;
		*current_user = Log_in(users,id,password);
		user_logged_in = true;
		std::cout << DONE_MESSAGE << std::endl;

	}
	else if(command == USER_CMD_TYPE_2)
	{
		*current_user = NULL;
		user_logged_in = false;
		std::cout << DONE_MESSAGE << std::endl;
	}
}

User* Post::Log_in(std::vector<User*> &users , std::string id , std::string password)
{

	for(int i=0 ; i<users.size() ; i++)
	{
		if(users[i]->is_Valid_Id(id))
		{
			if(users[i]->is_Valid_Password(password))
				return users[i];
			throw CommandException(ERROR_3);
		}	
	}
	throw CommandException(ERROR_2);
}


