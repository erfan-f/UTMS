#ifndef STUDENT
#define STUDENT

#include <string>
#include "user.h"


class Student : public User 
{
public:
	Student(std::string n,std::string i,std::string m,std::string m_i,std::string s,std::string p);
	void Print_Info();
	void Print_Page_Info();
	
private:
	std::string semester;

};

#endif