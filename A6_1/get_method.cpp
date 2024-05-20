#include "get_method.h"

Get::Get(std::string t , std::vector <std::string> cmds)
:Method(t,cmds) {}

void Get::Porcess_Cmd(std::string cmd_line ,std::vector<Major*> &majors ,std::vector<Unit*> &units ,std::vector<User*> &users , User **current_user,bool &user_logged_in)
{
	std::stringstream S(cmd_line);

	std::string temp_str,command;

	S >> temp_str >> command >> temp_str;

	if(command == USER_CMD_TYPE_3)
	{
		std::string id_operator,id;
		S >> id_operator >> id;
		if(std::stoi(id) <= 0)
			throw CommandException(ERROR_1);
	}
	if(command == USER_CMD_TYPE_5)
	{
		std::string id_operator,id;
		S >> id_operator >> id;
		if(std::stoi(id) < 0)
			throw CommandException(ERROR_1);
		//Print_Personal_Page(users,id);

	}
}

/*void Get::Print_Courses(std::vector<Unit*> &units , std::string id)
{
	bool course_validation = false;
	for(int i=0 ; i<units.size() ; i++)
	{
		if(units[i]->is_Valid_Id(id))
		{
			//units[i]->Print_Info();
			course_validation = true;
			break;
		}
	}
	if(!course_validation)
		return CommandException(ERROR_1);
}*/


/*void Get::Print_Personal_Page(std::vector<User*> &users,std::string id)
{
	bool user_validation = false;
	for(int i=0 ; i<users.size() ; i++)
	{
		if(users[i]->is_Valid_Id(id))
		{
			User *user = users[i];
			Student *student;
			student = dynamic_cast<Student*>(user);
			Professor *professor;
			users[i]->Print_Info();
			break;
		}
	}
}*/