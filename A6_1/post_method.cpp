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
		std::string operator_1 , operator_2 , input_1 , input_2;
		std::string id,password;
		S >> operator_1 >> input_1 >> operator_2 >> input_2;
		if((operator_1 == "id" || operator_1 == "password") && (operator_2 == "id" || operator_2 == "password"))
		{
			if(operator_1 == "id")
			{
				id = input_1;
				password = input_2;
			}
			else
			{
				id = input_2;
				password = input_1;
			}
		}
		else
			throw CommandException(ERROR_1);
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
		std::string operator_1 , operator_2 , input_1 , input_2;
		std::string title,message;
		Text_Reader(cmd_line,operator_1,operator_2,input_1,input_2);

		if((operator_1 == "title" || operator_1 == "message") && (operator_2 == "title" || operator_2 == "message"))
		{
			if(operator_1 == "title")
			{
				title = input_1;
				message = input_2;
			}
			else
			{
				title = input_2;
				message = input_1;
			}
		}
		else	
			throw CommandException(ERROR_1);
		
		UT_Post *p = new UT_Post{"",title,message};
		(*current_user)->Add_Post(p);

	}
	else if(command == USER_CMD_TYPE_6)
	{
		std::string target_id_operator,target_id;
		S >> target_id_operator >> target_id; 
		if(target_id_operator != "id")
			throw CommandException(ERROR_1);
		if(stoi(target_id) <= 0)
			throw CommandException(ERROR_1);
		Connect_Two_User(users,target_id,current_user);
		std::cout << DONE_MESSAGE << std::endl;
	}
	else if(command == USER_CMD_TYPE_8)
	{
		std::string course_id,professor_id,capacity_str,time,exam_date,class_number;
		std::string operator_1,operator_2,operator_3,operator_4,operator_5,operator_6;
		std::string input_1,input_2,input_3,input_4,input_5,input_6;

		std::string opr ,inp;
		for(int i=0 ; i<6 ; i++)
		{
			S >> opr >> inp;
			if(opr == "course_id")
				course_id = inp;
			else if(opr == "professor_id")
				professor_id = inp;
			else if(opr == "capacity")
				capacity_str = inp;
			else if(opr == "time")
				time = inp;
			else if(opr == "exam_date")
				exam_date = inp;
			else if(opr == "class_number")
				class_number = inp;
			else
				throw CommandException(ERROR_1);
		}

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
		Course *new_course = new Course(std::to_string(id),unit->get_Name(),professor->get_Name(),capacity,exam_date,time,class_number);
		courses.push_back(new_course);
		professor->Add_New_Course(new_course);

		Send_New_Course_Notification(users,professor_id,professor->get_Name(),NOTIFICATION_2);

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
	bool id_validation = false;
	for(int i=0 ; i<users.size() ; i++)
	{
		if(users[i]->is_Valid_Id(target_id))
		{
			id_validation = true;
			users[i]->Connect(*current_user);
			break;
		}
	}
	if(!id_validation)
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

void Post::Text_Reader(std::string cmd_line,std::string &opr1,std::string &opr2,std::string &inp1,std::string &inp2)
{
	std::stringstream S(cmd_line);
	std::string temp_str;
	S >> temp_str >> temp_str >> temp_str;
	
	S >> opr1;
	int first_delimiter = cmd_line.find('"');
	std::string str1 = cmd_line.erase(0,first_delimiter+1);
	int second_delimiter = cmd_line.find('"');
	std::string str2 = cmd_line.substr(0,second_delimiter);

	inp1 = '"' + str2 + '"';

	std::string new_cmd_line = cmd_line.erase(0,second_delimiter+1);
	std::stringstream S2(new_cmd_line);
	S2 >> opr2;

	first_delimiter = new_cmd_line.find('"');
	std::string str3 = new_cmd_line.erase(0,first_delimiter+1);
	second_delimiter = new_cmd_line.find('"');
	std::string str4 = new_cmd_line.substr(0,second_delimiter);

	inp2 = '"' + str4 + '"';
}


void Post::Send_New_Course_Notification(std::vector<User*> users,std::string id,std::string name,std::string notice_text)
{
	Notification *new_notif = new Notification{id,name,notice_text};
	for(int i=1 ; i<users.size() ; i++)
	{
		users[i]->Recieve_Notification(new_notif);
	}
}