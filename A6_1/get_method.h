#ifndef GET
#define GET

#include <string>
#include "method.h"

class Get : public Method
{
public:
	Get(std::string t , std::vector <std::string> cmds);
	void Process_Cmd(std::string cmd_line ,std::vector<Major*> &majors ,std::vector<Unit*> &units ,std::vector<User*> &users ,std::vector<Course*> &courses, User **current_user,bool &user_logged_in);
	void Print_All_Courses(std::vector<Course*> courses);
	void Print_Course(std::vector<Course*> courses , std::string course_id);
	void Print_Personal_Page(std::vector<User*> &users,std::string user_id);
	void Print_User_Posts(std::vector<User*> &users,std::string user_id,std::string post_id);

};

#endif