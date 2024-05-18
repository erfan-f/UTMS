#include "student.h"

Student::Student(std::string n,std::string i,std::string m_i,std::string s,std::string p)
:User(n,i,m_i,p)
{
	semester = s;
}