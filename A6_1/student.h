#ifndef STUDENT
#define STUDENT

#include <string>
#include "user.h"


class Student : public User 
{
public:
	Student(std::string n,std::string i,std::string m_i,std::string s,std::string p);

private:
	std::string semester;
};

#endif