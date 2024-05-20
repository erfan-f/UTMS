#ifndef USER
#define USER

#include <iostream>
#include <string>
#include <vector>
#include "exception.h"
#include "commands.h"
#include "messages.h"
#include "UT_post.h"
#include "unit.h"

const std::string USER_TYPE_1 = "Professor";
const std::string USER_TYPE_2 = "Student";
const std::string USER_TYPE_3 = "Operator";



class User
{
public:
	User(std::string n,std::string i,std::string p);
	User(std::string n,std::string i,std::string m_i,std::string p);
	virtual bool is_Valid_Id (std::string i);
	bool is_Valid_Password(std::string p);
	bool is_Professor();
	bool is_Student();
	void Add_Post(UT_Post post);
	void Connect(User *target);
	void Print_Info();
	bool Permision_Check(std::string cmd);
	std::string get_Type();
	std::string get_Major_Id();

protected:	
	std::string user_type;
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