#ifndef PROFESSOR
#define PROFESSOR
#include <string>
#include "user.h"

class Professor : public User 
{
public:
	Professor(std::string n,std::string i,std::string m,std::string m_i,std::string po,std::string p);
	void Add_New_Course(Course *new_course);
	bool is_Free(std::string time);
	void Print_Info();
	void Print_Page_Info();

private:
	std::string position;
};


#endif