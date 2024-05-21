#include "student.h"

Student::Student(std::string n,std::string i,std::string m,std::string m_i,std::string s,std::string p)
:User(n,i,m,m_i,p)
{
	semester = s;
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

void Student::Print_Info()
{
	std::cout << name << " " << major << " " << semester << " ";
	for(int i=0 ; i<courses.size() ; i++)
	{
		std::cout << courses[i]->get_Name();
		if(i != courses.size() - 1)
			std::cout << ",";
	}
	std::cout << std::endl;
}

void Student::Print_Page_Info()
{
	Print_Info();
	
	Sort_Posts();
	for(int j=0 ; j<posts.size() ; j++)
	{
		std::cout <<  posts[j]->id << " " << posts[j]->title << std::endl;
	}
	
}