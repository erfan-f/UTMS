#ifndef MAJOR
#define MAJOR

#include <string>

class Major
{
public:
	Major(std::string n , std::string i);
	bool is_Valid_Id(std::string i);
	std::string get_Name();
private:
	std::string name;
	std::string id;
};

#endif