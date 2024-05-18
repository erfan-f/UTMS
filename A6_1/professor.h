#ifndef PROFESSOR
#define PROFESSOR
#include <string>
#include "user.h"


class Professor : public User 
{
public:
	Professor(std::string n,std::string i,std::string m_i,std::string po,std::string p);

private:
	std::string position;
};

#endif