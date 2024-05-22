#include "professor.hpp"

Professor::Professor(std::string n,std::string i,std::string m,std::string m_i,std::string po,std::string p)
:User(n,i,m,m_i,p)
{
	position = po;
	user_type = USER_TYPE_1;

	valid_cmds.push_back(USER_CMD_TYPE_1);
	valid_cmds.push_back(USER_CMD_TYPE_2);
	valid_cmds.push_back(USER_CMD_TYPE_3);
	valid_cmds.push_back(USER_CMD_TYPE_4);
	valid_cmds.push_back(USER_CMD_TYPE_5);
	valid_cmds.push_back(USER_CMD_TYPE_6);
	valid_cmds.push_back(USER_CMD_TYPE_7);

}


void Professor::Add_New_Course(Course *new_course)
{
	courses.push_back(new_course);
}

bool Professor::is_Free(std::string time)
{
	for(int i=0 ; i<courses.size() ; i++)
	{
		if(courses[i]->is_Interrupted(time))
			return false;
	}
	return true;
}


void Professor::Print_Info()
{
	std::cout << name << " " << major << " " << position << " ";
	for(int i=0 ; i<courses.size() ; i++)
	{
		std::cout << courses[i]->get_Name();
		if(i != courses.size() - 1)
			std::cout << ",";
	}

	std::cout << std::endl;

}

void Professor::Print_Page_Info()
{
	Print_Info();
	
	Sort_Posts();

	for(int j=0 ; j<posts.size() ; j++)
	{
		std::cout <<  posts[j]->id << " " << posts[j]->title << std::endl;
	}	
}









