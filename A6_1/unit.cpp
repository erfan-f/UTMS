#include "unit.h"

Unit::Unit(std::string n,std::string i,int c,std::string pr,std::vector<std::string> m_i)
{
	name = n;
	id = i;
	credit = c;
	prerequisite = pr;
	majors_id = m_i;
}