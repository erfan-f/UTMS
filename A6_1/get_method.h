#ifndef GET
#define GET

#include <string>
#include "method.h"

class Get : public Method
{
public:
	Get(std::string t , std::vector <std::string> cmds);
	void Porcess_Cmd(std::string cmd_line ,std::vector<Major*> &majors ,std::vector<Unit*> &units ,std::vector<User*> &users , User **current_user,bool &user_logged_in);
	//void Get::Print_Courses(std::vector<Unit*> &units);

};

#endif