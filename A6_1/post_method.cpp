#include "post_method.h"

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
		S >> operator_id >> id >> operator_password >> password;
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
	else if(command == USER_CMD_TYPE_4)
	{
		std::string title_operator,title,message_operator,message;
		S >> title_operator >> title >> message_operator >> message;
		UT_Post p = {title,message};
		(*current_user)->Add_Post(p);

	}
	else if(command == USER_CMD_TYPE_6)
	{
		std::string target_id_operator,target_id;
		S >> target_id_operator >> target_id; 
		if(stoi(target_id) <= 0)
			throw CommandException(ERROR_1);
		Connect_Two_User(users,target_id,current_user);
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

void Post::Connect_Two_User(std::vector<User*> &users , std::string target_id ,User **current_user)
{
	bool valid_id = false;
	for(int i=0 ; i<users.size() ; i++)
	{
		if(users[i]->is_Valid_Id(target_id))
		{
			valid_id = true;
			users[i]->Connect(*current_user);
			(*current_user)->Connect(users[i]);
		}
	}
	if(!valid_id)
		throw CommandException(ERROR_2);
}

