#ifndef USER
#define USER

#include <iostream>
#include <string>
#include <vector>
#include "exception.h"
#include "commands.h"
#include "messages.h"
#include "UT_post.h"




class User
{
public:
	User(std::string n,std::string i,std::string m_i,std::string p);
	void give_Access(std::vector<std::string> cmds);
	bool is_Valid_Id (std::string i);
	bool is_Valid_Password(std::string p);
	void Add_Post(UT_Post post);
	void Connect(User *target);
protected:
	std::string name;
	std::string id;
	std::string major_id;
	std::string password;
	bool logged_in;
	std::vector<std::string> valid_cmds;
	std::vector<UT_Post> posts;
	std::vector<User*> connection_list;
};

#endif