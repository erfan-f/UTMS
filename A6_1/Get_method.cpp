#include "Get_method.hpp"

Get::Get(std::string t , std::vector <std::string> cmds)
:Method(t,cmds) {}

void Get::Process_Cmd(std::string cmd_line ,std::vector<Major*> &majors ,std::vector<Unit*> &units ,std::vector<User*> &users ,std::vector<Course*> &courses, User **current_user)
{
	std::stringstream S(cmd_line);

	std::string temp_str,command;

	S >> temp_str >> command >> temp_str;

	if(command == USER_CMD_TYPE_3)
	{
		std::string id_argument,id,garbage_string;
		S >> id_argument >> id >> garbage_string;
		if(id_argument == "")
		{
			Print_All_Courses(courses);
		}
		else
		{
			if(id_argument != CMD_ARGUMENT_1)
				throw ArgumentException(ERROR_1);
			if(std::stoi(id) <= 0)
				throw ArgumentException(ERROR_1);
			if(garbage_string != "")
				throw ArgumentException(ERROR_1);

			Print_Course(courses,id);
		}
	}
	else if(command == USER_CMD_TYPE_4)
	{
		std::string argument_1,argument_2,input_1,input_2,garbage_string;
		std::string id,post_id;
		S >> argument_1 >> input_1 >> argument_2 >> input_2 >> garbage_string;
		if((argument_1 == CMD_ARGUMENT_1 || argument_1 == CMD_ARGUMENT_3 ) && (argument_2 == CMD_ARGUMENT_1 || argument_2 == CMD_ARGUMENT_3))
		{
			if(argument_1 == CMD_ARGUMENT_1)
			{
				id = input_1;
				post_id = input_2;
			}
			else
			{
				id = input_2;
				post_id = input_1;
			}
		}
		else
			throw ArgumentException(ERROR_1);

		if(std::stoi(id) <=0 || std::stoi(post_id) <=0)
			throw ArgumentException(ERROR_1);
		
		if(garbage_string != "")
			throw ArgumentException(ERROR_1);

		Print_User_Posts(users,id,post_id);
	}
	else if(command == USER_CMD_TYPE_5)
	{
		std::string id_argument,id,garbage_string;
		S >> id_argument >> id >> garbage_string;
		if(id_argument != CMD_ARGUMENT_1)
			throw ArgumentException(ERROR_1);
		if(std::stoi(id) < 0)
			throw ArgumentException(ERROR_1);
		if(garbage_string != "")
			throw ArgumentException(ERROR_1);

		Print_Personal_Page(users,id);
	}
	else if(command == USER_CMD_TYPE_7)
	{
		std::string argument_str;
		S >> argument_str;
		
		if(argument_str != "")
			throw ArgumentException(ERROR_1);
		
		(*current_user)->Print_Notifications();
	}
	else if(command == USER_CMD_TYPE_9)
	{
		std::string argument_str;
		S >> argument_str;
		if(argument_str != "")
			throw ArgumentException(ERROR_1);

		Student *student = dynamic_cast<Student*>(*current_user);
		if(student == NULL)
            throw AcessibilityException(ERROR_3);

		student->Print_Courses();
	}
}


void Get::Print_All_Courses(std::vector<Course*> courses)
{	
	if(courses.size() == 0)
		throw CommandException(ERROR_4);

	for(int i=0 ; i<courses.size(); i++)
	{
		courses[i]->Print_Info();
	}
	
}

void Get::Print_Course(std::vector<Course*> courses , std::string course_id)
{
	Course *target_course;
	bool id_validation = false;
	for(int i=0 ; i<courses.size() ; i++)
	{
		if(courses[i]->is_Valid_Id(course_id))
		{
			id_validation = true;
			target_course = courses[i];
			break;
		}
	}
	if(!id_validation)
		throw CommandException(ERROR_2);
	
	target_course->Print_All_Info();
}


void Get::Print_Personal_Page(std::vector<User*> &users,std::string user_id)
{
	User *user;
	bool id_validation = false;
	for(int i=0 ; i<users.size() ; i++)
	{
		if(users[i]->is_Valid_Id(user_id))
		{
			id_validation = true;
			user = users[i];
			break;
		}
	}
	if(!id_validation)
		throw CommandException(ERROR_2);

	user->Print_Page_Info();
}

void Get::Print_User_Posts(std::vector<User*> &users,std::string user_id,std::string post_id)
{
	User *user;
	bool id_validation = false;
	for(int i=0 ; i<users.size() ; i++)
	{
		if(users[i]->is_Valid_Id(user_id))
		{
			id_validation = true;
			user = users[i];
			break;
		}
	}
	if(!id_validation)
		throw CommandException(ERROR_2);
	
	user->Print_Post(post_id);
}