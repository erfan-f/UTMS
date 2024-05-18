#ifndef SYSTEM_CONTROLLER
#define SYSTEM_CONTROLLER

#include "iostream"
#include <vector>
#include <fstream>
#include <sstream>

#include "exception.h"
#include "major.h"
#include "unit.h"
#include "user.h"
#include "professor.h"
#include "student.h"
#include "method.h"
#include "post.h"
#include "messages.h"


const char SEPRATOR = ',';
const char IN_LINE_SEPRATOR = ';';

const int NUM_OF_METHOD = 4;
const std::string METHOD_1 = "POST";
const std::string METHOD_2 = "GET";
const std::string METHOD_3 = "PUT";
const std::string METHOD_4 = "DELETE";

const std::string ARGUMANT = "?";



class SystemController
{
public:
	SystemController();
	void Read_Majors(std::string file_path);
	void Read_Units(std::string file_path);
	void Read_Users(std::string file_path);
	void Add_Major(std::string name,std::string id);
	void Add_Unit(std::string name,std::string id,int credit,std::string prerequisite,std::vector<std::string> majors_id);
	void Add_Professor(std::string name,std::string id,std::string major_id,std::string position,std::string password);
	void Add_Student(std::string name,std::string id,std::string major_id,std::string semester,std::string password);
	void Handle_Cmd(std::string cmd_line);
	Method* Specify_Method(std::string method_type);
	void give_User_Access();


private:
	std::vector<User*> users;
	std::vector<Major*> majors;
	std::vector<Unit*> units;
	std::vector<Method*> methods;
	std::vector<std::string> user_cmds;
	bool user_logged_in;
	User *current_user;
};

#endif