#include "student.h"

Student::Student(std::string n,std::string i,std::string m,std::string m_i,std::string s,std::string p)
:User(n,i,m_i,p)
{
	semester = s;
	major = m;
	user_type = USER_TYPE_2;

	valid_cmds.push_back(USER_CMD_TYPE_1);
	valid_cmds.push_back(USER_CMD_TYPE_2);
	valid_cmds.push_back(USER_CMD_TYPE_3);
	valid_cmds.push_back(USER_CMD_TYPE_4);
	valid_cmds.push_back(USER_CMD_TYPE_5);
	valid_cmds.push_back(USER_CMD_TYPE_6);
	valid_cmds.push_back(USER_CMD_TYPE_7);
	valid_cmds.push_back(USER_CMD_TYPE_9);
}