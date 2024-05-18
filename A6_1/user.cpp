#include "user.h"

User::User(std::string n,std::string i,std::string m_i,std::string p)
{
	name = n;
	id = i;
	major_id = m_i;
	password = p;
	logged_in = false;
}

void User::give_Access(std::vector<std::string> cmds)
{
	valid_cmds = cmds;
}

bool User::is_Valid_Id(std::string i)
{
	if(id == i)
		return true;
	return false;
}

bool User::is_Valid_Password(std::string p)
{
	if(password == p)
		return true;
	return false;
}

