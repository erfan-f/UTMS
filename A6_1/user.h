#ifndef USER
#define USER

#include <string>
#include <vector>
#include "commands.h"



class User
{
public:
	User(std::string n,std::string i,std::string m_i,std::string p);
	void give_Access(std::vector<std::string> cmds);
	bool is_Valid_Id (std::string i);
	bool is_Valid_Password(std::string p);
protected:
	std::string name;
	std::string id;
	std::string major_id;
	std::string password;
	bool logged_in;
	std::vector<std::string> valid_cmds;
};

#endif