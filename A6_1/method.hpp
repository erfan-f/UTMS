#ifndef METHOD
#define METHOD

#include <iostream>
#include <vector>
#include <string>
#include <sstream>


#include "exception.hpp"
#include "major.hpp"
#include "unit.hpp"
#include "user.hpp"
#include "professor.hpp"
#include "student.hpp"
#include "commands.hpp"
#include "messages.hpp"
#include "course.hpp"




class Method
{
public:
	Method(std::string t , std::vector <std::string> cmds);
	bool is_Equal(std::string m);
	bool is_Cmd_Valid(std::string cmd);
	virtual void Process_Cmd(std::string cmd_line ,std::vector<Major*> &majors ,std::vector<Unit*> &units ,std::vector<User*> &users ,std::vector<Course*> &courses, User **current_user,bool &user_logged_in) = 0;
protected:
	std::string type;
	std::vector<std::string> commands;

};
#endif