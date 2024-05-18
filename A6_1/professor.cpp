#include "professor.h"

Professor::Professor(std::string n,std::string i,std::string m_i,std::string po,std::string p)
:User(n,i,m_i,p)
{
	position = po;
}