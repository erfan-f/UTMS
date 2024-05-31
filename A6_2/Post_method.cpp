#include "Post_method.hpp"

Post::Post(std::string t , std::vector <std::string> cmds)
:Method(t,cmds){}


void Post::Process_Cmd(std::string cmd_line,std::vector<Major*> &majors,std::vector<Unit*> &units,std::vector<User*> &users ,std::vector<Course*> &courses, User **current_user,std::vector<std::string> &response)
{
	std::stringstream S(cmd_line);

	std::string temp_str , command;

	S >> temp_str;
	S >> command;
	S >> temp_str;

	if(command == USER_CMD_TYPE_1)
	{
		std::string argument_1,argument_2,input_1,input_2,garbage_string;
		std::string id,password;
		S >> argument_1 >> input_1 >> argument_2 >> input_2 >> garbage_string;

		if(garbage_string != "")
			throw ArgumentException(ERROR_1);

		if((argument_1 == CMD_ARGUMENT_1 || argument_1 == CMD_ARGUMENT_2) && (argument_2 == CMD_ARGUMENT_1 || argument_2 == CMD_ARGUMENT_2))
		{
			if(argument_1 == CMD_ARGUMENT_1)
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
			throw ArgumentException(ERROR_1);

		if(!is_Number(id))
            throw ArgumentException(ERROR_1);

		*current_user = User_Login(users,id,password);
		
		std::ostringstream os;
        os << DONE_MESSAGE << std::endl;
        response.push_back(os.str());
	}
	else if(command == USER_CMD_TYPE_2)
	{
		std::string garbage_string;
		S >> garbage_string;
		if(garbage_string != "")
			throw ArgumentException(ERROR_1);
		(*current_user)->Logout();
		*current_user = NULL;

		std::ostringstream os;
        os << DONE_MESSAGE << std::endl;
        response.push_back(os.str());
	}
	else if(command == USER_CMD_TYPE_4)
	{
		//std::string argument,argument_1,argument_2,argument_3,input_1,input_2,input_3;
		std::string argument,garbage_str;
		std::string title,message,image;
		bool title_is_entered = false;
		bool message_is_entered = false;
		bool image_is_entered = false;

		for(int i=0 ; i<3 ; i++)
		{
			S >> argument;
			if(argument == CMD_ARGUMENT_4 && !title_is_entered)
			{
				title = Text_Reader(cmd_line);
				title_is_entered = true;
				S.str(cmd_line);
			}
			else if(argument == CMD_ARGUMENT_5 && !message_is_entered)
			{
				message = Text_Reader(cmd_line);
				message_is_entered = true;
				S.str(cmd_line);
			}
			else if(argument == CMD_ARGUMENT_12 && !image_is_entered)
			{
				S >> image;
				image_is_entered = true;
				int image_string_position = cmd_line.find(image);
				cmd_line.erase(0,image_string_position + image.length());
			}
			else 
				throw ArgumentException(ERROR_1);
		}
		
		S >> garbage_str;
		if(garbage_str != "" || title == "" || message ==  ""  || image == "")
			throw ArgumentException(ERROR_1);

		UT_Post *p = new UT_Post{"",title,message,image};
		(*current_user)->Add_Post(p);

		std::ostringstream os;
        os << DONE_MESSAGE << std::endl;
        response.push_back(os.str());
	}
	else if(command == USER_CMD_TYPE_6)
	{
		std::string target_id_argument,target_id,garbage_string;
		S >> target_id_argument >> target_id >> garbage_string; 
		if(target_id_argument != CMD_ARGUMENT_1 || target_id == "")
			throw ArgumentException(ERROR_1);

		if(!is_Number(target_id))
            throw ArgumentException(ERROR_1);

		if(stoll(target_id) <= 0)
			throw ArgumentException(ERROR_1);
		if(garbage_string != "")
			throw ArgumentException(ERROR_1);

		if((*current_user)->get_Id() == target_id)
			throw AcessibilityException(ERROR_3);

		Connect_Two_User(users,target_id,current_user);
		std::ostringstream os;
        os << DONE_MESSAGE << std::endl;
        response.push_back(os.str());
	}
	else if(command == USER_CMD_TYPE_8)
	{
		std::string course_id,professor_id,capacity_str,time,exam_date,class_number,garbage_string;
		std::string operator_1,operator_2,operator_3,operator_4,operator_5,operator_6;
		std::string input_1,input_2,input_3,input_4,input_5,input_6;
		bool arg_1_entered = false;
		bool arg_2_entered = false;
		bool arg_3_entered = false;
		bool arg_4_entered = false;
		bool arg_5_entered = false;
		bool arg_6_entered = false;
		std::string opr ,inp;
		for(int i=0 ; i<6 ; i++)
		{
			S >> opr >> inp ;
			if(inp == "")
				throw ArgumentException(ERROR_1);
			if(opr == CMD_ARGUMENT_6 && !arg_1_entered)
			{
				course_id = inp;
				arg_1_entered = true;
			}
			else if(opr == CMD_ARGUMENT_7 && !arg_2_entered)
			{
				professor_id = inp;
				arg_2_entered = true;
			}
			else if(opr == CMD_ARGUMENT_8 && !arg_3_entered)
			{
				capacity_str = inp;
				arg_3_entered = true;
			}
			else if(opr == CMD_ARGUMENT_9 && !arg_4_entered)
			{
				time = inp;
				arg_4_entered = true;				
			}	
			else if(opr == CMD_ARGUMENT_10 && !arg_5_entered)
			{
				exam_date = inp;
				arg_5_entered = true;				
			}
			else if(opr == CMD_ARGUMENT_11 && !arg_6_entered)
			{
				class_number = inp;
				arg_6_entered = true;				
			}	
			else
				throw ArgumentException(ERROR_1);
			inp = "";
		}
		S >> garbage_string;
		if(garbage_string != "")
			throw ArgumentException(ERROR_1);

		if(!is_Number(capacity_str)  || !is_Number(class_number) || !is_Number(course_id) || !is_Number(professor_id))
            throw ArgumentException(ERROR_1);

		int capacity = std::stoll(capacity_str);

		if(capacity <=0 || std::stoll(class_number) <=0 || std::stoll(course_id) <=0 || std::stoll(professor_id) <=0)
			throw ArgumentException(ERROR_1);

		Unit *unit = Find_Unit(units,course_id);
		User *user = Find_User(users,professor_id);

		Professor *professor = dynamic_cast<Professor*>(user);
		if(professor == NULL)
			throw AcessibilityException(ERROR_3);


		if(!unit->is_Valid_Major(professor->get_Major_Id()))
			throw AvailabilityException(ERROR_3);		

		if(!professor->is_Free(time))
			throw AvailabilityException(ERROR_3);

		int id = courses.size() + 1;
		Course *new_course = new Course(std::to_string(id),unit->get_Name(),professor->get_Name(),professor_id,capacity,unit->get_Majors_Id(),unit->get_Prerequisite(),exam_date,time,class_number);
		courses.push_back(new_course);
		professor->Add_New_Course(new_course);

		Send_Public_Notification(users,professor_id,professor->get_Name(),NOTIFICATION_2);

		std::ostringstream os;
        os << DONE_MESSAGE << std::endl;
        response.push_back(os.str());
	}
	else if(command == USER_CMD_TYPE_10)
	{
		std::string phtoto_argument,photo_address;
		S >> phtoto_argument >> photo_address;
		if((phtoto_argument != CMD_ARGUMENT_13) || photo_address == "")
			throw ArgumentException(ERROR_1);

		(*current_user)->Set_Profile_Photo(photo_address);
		std::ostringstream os;
        os << DONE_MESSAGE << std::endl;
        response.push_back(os.str());
	}	
}

User* Post::User_Login(std::vector<User*> &users , std::string id , std::string password)
{
	for(int i=0 ; i<users.size() ; i++)
	{
		if(users[i]->is_Valid_Id(id))
		{
			if(users[i]->is_Valid_Password(password))
			{
				users[i]->Login();
				return users[i];
			}
			throw AvailabilityException(ERROR_3);
		}	
	}
	throw AvailabilityException(ERROR_2);
}

void Post::Connect_Two_User(std::vector<User*> &users , std::string target_id ,User **current_user)
{
	User *target_user = Find_User(users,target_id);

	target_user->Connect(*current_user);
	(*current_user)->Connect(target_user);
}


std::string Post::Text_Reader(std::string &cmd_line)
{
	int first_delimiter = cmd_line.find(TEXT_CHAR);
	std::string temp_str = cmd_line.erase(0,first_delimiter+1);
	int second_delimiter = cmd_line.find(TEXT_CHAR);
	if(second_delimiter == -1 || first_delimiter == -1)
		throw ArgumentException(ERROR_1);
	std::string text = cmd_line.substr(0,second_delimiter);
	cmd_line.erase(0,second_delimiter+1);

	return TEXT_CHAR + text + TEXT_CHAR;
}


void Post::Send_Public_Notification(std::vector<User*> users,std::string id,std::string name,std::string notice_text)
{
	for(int i=1 ; i<users.size() ; i++)
	{
		users[i]->Recieve_Notification(new Notification{id,name,notice_text});
	}
}