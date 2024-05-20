#include "post_method.h"

Post::Post(std::string t , std::vector <std::string> cmds)
:Method(t,cmds){}


void Post::Process_Cmd(std::string cmd_line ,std::vector<Major*> &majors ,std::vector<Unit*> &units ,std::vector<User*> &users ,std::vector<Course*> &courses, User **current_user,bool &user_logged_in)
{
	std::stringstream S(cmd_line);

	std::string temp_str , command;

	S >> temp_str;
	S >> command;
	S >> temp_str;
	if(command == USER_CMD_TYPE_1)
	{
		std::string id_operator,id,password_operator,password;
		S >> id_operator >> id >> password_operator >> password;
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
	else if(command == USER_CMD_TYPE_8)
	{
		std::string course_id_operator,course_id;
		std::string professor_id_operator,professor_id;
		std::string capacity_operator,capacity_str;
		std::string time_operator,time;
		std::string exam_date_operator,exam_date;
		std::string class_number_operator,class_number;
		S >> course_id_operator >> course_id;
		S >> professor_id_operator >> professor_id;
		S >> capacity_operator >> capacity_str;
		S >> time_operator >> time;		
		S >> exam_date_operator >> exam_date;
		S >> class_number_operator >> class_number;

		int capacity = std::stoi(capacity_str);

		if(capacity <=0 || std::stoi(class_number) <=0)
			throw CommandException(ERROR_1);

		Unit *unit = Specify_Unit(units,course_id);
		User *user = Specify_User(users,professor_id);

		Professor *professor = dynamic_cast<Professor*>(user);
		if(professor == NULL)
			throw CommandException(ERROR_3);


		if(!unit->is_Valid_Major(professor->get_Major_Id()))
			throw CommandException(ERROR_3);		

		if(!professor->is_Free(time))
			throw CommandException(ERROR_3);

		int id = courses.size() + 1;
		Course *new_course = new Course(std::to_string(id),unit->get_Name(),professor_id,capacity,exam_date,time,class_number);
		courses.push_back(new_course);
		professor->Add_New_Course(new_course);

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


User* Post::Specify_User(std::vector<User*> &users , std::string professor_id)
{
	User *user;
	bool id_validation = false;
	for(int i=0 ; i<users.size() ; i++)
	{
		if(users[i]->is_Valid_Id(professor_id))
		{
			id_validation =true;
			user = users[i];
			break;
		}	
	}
	if(!id_validation)
		throw CommandException(ERROR_2);
	return user;

}

Unit* Post::Specify_Unit(std::vector<Unit*> units, std::string unit_id)
{
	Unit *unit;
	bool id_validation = false;
	for(int i=0 ; i<units.size() ; i++)
	{
		if(units[i]->is_Valid_Id(unit_id))
		{
			id_validation = true;
			unit = units[i];
			break;
		}
	}
	if(!id_validation)
		throw CommandException(ERROR_2);
	return unit;	
}
