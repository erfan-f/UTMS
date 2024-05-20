#ifndef PROFESSOR
#define PROFESSOR
#include <string>
#include "user.h"
#include "course.h"

class Professor : public User 
{
public:
	Professor(std::string n,std::string i,std::string m_i,std::string po,std::string p);
	void Add_New_Course(Course *new_course);
	bool is_Free(std::string time);

private:
	std::string position;
	std::vector <Course *> courses;
};

#endif