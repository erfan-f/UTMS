#ifndef UNIT
#define UNIT

#include <string>
#include <vector>


class Unit
{
public:
	Unit(std::string n,std::string i,int c,std::string pr,std::vector<std::string> m_i);
private:
	std::string name;
	std::string id;
	int credit;
	std::string prerequisite;
	std::vector<std::string> majors_id;
};

#endif