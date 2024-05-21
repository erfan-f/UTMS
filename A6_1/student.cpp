#include "student.hpp"

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

bool Student::is_Allowed_to_Take(Course* new_course)
{
	if(!new_course->is_Valid_Semester(semester))
		return false;
	if(!new_course->is_Valid_Major(major_id))
		return false;
	
	for(int i=0 ; i<courses.size() ; i++)
	{
		if(courses[i]->is_Interrupted(new_course))
			return false;
	}

	courses.push_back(new_course);

	return true;
}

void Student::Delete_Course(std::string course_id)
{
	bool id_validation = false;
	for(int i=0 ; i<courses.size() ; i++)
	{
		if(courses[i]->is_Valid_Id(course_id))
		{
			id_validation = true;
			delete courses[i];
			courses.erase(courses.begin() + i);
			break;
		}
	}
	if(!id_validation)
		throw CommandException(ERROR_2);
}


void Student::Print_Courses()
{
	if(courses.size() == 0)
		throw CommandException(ERROR_4);
	for(int i=0 ; i<courses.size() ; i++)
	{
		courses[i]->Print_All_Info();
	}
}
