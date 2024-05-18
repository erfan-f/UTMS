#ifndef MAJOR
#define MAJOR

#include <string>

class Major
{
public:
	Major(std::string n , std::string i);
private:
	std::string name;
	std::string id;
};

#endif