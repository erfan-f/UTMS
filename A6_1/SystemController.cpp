#include "SystemController.h"

SystemController::SystemController()
{
	user_logged_in  = false;

	Post *post = new Post(METHOD_1,{"login","logout","connect","post"});
	
	methods.push_back(post);

	give_User_Access();
}


void SystemController::Read_Majors(std::string file_path)
{
	std::string  name,id;

	std::fstream fin;
	fin.open(file_path,std::ios::in);

	std::string temp_str;
	getline(fin,temp_str);

	while(getline(fin,temp_str))
	{
		std::stringstream S(temp_str);
		getline(S,id,SEPRATOR);
		getline(S,name,SEPRATOR);

		Add_Major(id,name);
	}

}

void SystemController::Read_Units(std::string file_path)
{
	std::string  name,id,credit,prerequisite,majors_id_str;
	std::vector<std::string> majors_id;

	std::fstream fin;
	fin.open(file_path,std::ios::in);

	std::string temp_str;
	getline(fin,temp_str);

	while(getline(fin,temp_str))
	{
		std::stringstream S(temp_str);
		getline(S,id,SEPRATOR);
		getline(S,name,SEPRATOR);
		getline(S,credit,SEPRATOR);
		getline(S,prerequisite,SEPRATOR);
		getline(S,majors_id_str,SEPRATOR);

		std::stringstream S2(majors_id_str);
		while(getline(S2,temp_str,IN_LINE_SEPRATOR))
		{
			majors_id.push_back(temp_str);
		}

		Add_Unit(name,id,std::stoi(credit),prerequisite,majors_id);
		majors_id.clear();
	}
}

void SystemController::Read_Users(std::string file_path)
{

	std::string  name,id,major_id,position_or_semester,password;

	std::fstream fin;
	fin.open(file_path,std::ios::in);

	std::string temp_str;
	getline(fin,temp_str);

	while(getline(fin,temp_str))
	{
		std::stringstream S(temp_str);
		getline(S,id,SEPRATOR);
		getline(S,name,SEPRATOR);
		getline(S,major_id,SEPRATOR);
		getline(S,position_or_semester,SEPRATOR);
		getline(S,password,SEPRATOR);
		
		Add_Professor(name,id,major_id,position_or_semester,password);
	}
}


void SystemController::Add_Major(std::string name,std::string id)
{
	Major *m = new Major(name,id);
	majors.push_back(m);
}

void SystemController::Add_Unit(std::string name,std::string id,int credit,std::string prerequisite,std::vector<std::string> majors_id)
{
	Unit *u = new Unit(name,id,credit,prerequisite,majors_id);
	units.push_back(u);
}

void SystemController::Add_Professor(std::string name,std::string id,std::string major_id,std::string position,std::string password)
{
	Professor *p = new Professor(name,id,major_id,position,password);
	users.push_back(p);
}

void SystemController::Add_Student(std::string name,std::string id,std::string major_id,std::string semester,std::string password)
{
	Student *s = new Student(name,id,major_id,semester,password);
	users.push_back(s);
}

void SystemController::Handle_Cmd(std::string cmd_line)
{
	std::stringstream S(cmd_line);

	std::string method_type , command , operator_argument;

	S >> method_type;
	S >> command;
	S >> operator_argument;

	Method *method = Specify_Method(method_type);

	if(!method->is_Cmd_Valid(command))
		throw CommandException(ERROR_2);

	if(operator_argument != ARGUMANT)
		throw CommandException(ERROR_1);

	if(command == USER_CMD_TYPE_1 && user_logged_in)
		throw CommandException(ERROR_3);
	else if(command != USER_CMD_TYPE_1 && !user_logged_in)
		throw CommandException(ERROR_3);

	method->Process_Cmd(cmd_line,majors,units,users,&current_user,user_logged_in);

}

Method* SystemController::Specify_Method(std::string method_type)
{
	for(int i=0 ; i<methods.size() ; i++)
	{
		if(methods[i]->is_Equal(method_type))
		{
			return methods[i];
		}
	}
	throw MethodException(ERROR_1);
}

void SystemController::give_User_Access()
{
	user_cmds.push_back(USER_CMD_TYPE_1);
	user_cmds.push_back(USER_CMD_TYPE_2);
	user_cmds.push_back(USER_CMD_TYPE_3);
	user_cmds.push_back(USER_CMD_TYPE_4);
	user_cmds.push_back(USER_CMD_TYPE_5);
	user_cmds.push_back(USER_CMD_TYPE_6);
	user_cmds.push_back(USER_CMD_TYPE_7);
	for(int i=0 ; i<users.size() ; i++)
	{
		users[i]->give_Access(user_cmds);
	}
}

