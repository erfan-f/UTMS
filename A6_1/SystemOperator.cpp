#include "SystemOperator.h"

SystemOperator::SystemOperator(std::string n , std::string i , std::string pass)
:User(n,i,pass) 
{
	user_type = USER_TYPE_3;

    valid_cmds.push_back(USER_CMD_TYPE_1);
	valid_cmds.push_back(USER_CMD_TYPE_2);
	valid_cmds.push_back(USER_CMD_TYPE_4);
	valid_cmds.push_back(USER_CMD_TYPE_8);

}

void SystemOperator::Print_Info()
{
	std::cout << "UT_account" << std::endl;
}

void SystemOperator::Print_Page_Info()
{
	Print_Info();
	
	Sort_Posts();
	for(int j=0 ; j<posts.size() ; j++)
	{
		std::cout <<  posts[j]->id << " " << posts[j]->title << std::endl;
	}
}