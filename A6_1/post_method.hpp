#ifndef POST
#define POST

#include <string>
#include "method.hpp"
#include "UT_post.hpp"


class Post : public Method
{
public:
	Post(std::string t , std::vector <std::string> cmds);
	void Process_Cmd(std::string cmd_line ,std::vector<Major*> &majors ,std::vector<Unit*> &units ,std::vector<User*> &users ,std::vector<Course*> &courses, User **current_user,bool &user_logged_in);
	User* Log_in(std::vector<User*> &users , std::string id , std::string password);
	void Connect_Two_User(std::vector<User*> &users , std::string target_id ,User **current_user);
	User* Specify_User(std::vector<User*> &users , std::string professor_id);
	Unit* Specify_Unit(std::vector<Unit*> , std::string unit_id);
	void Text_Reader(std::string cmd_line,std::string &opr1,std::string &opr2,std::string &inp1,std::string &inp2);
	void Send_New_Course_Notification(std::vector<User*> users,std::string id,std::string name,std::string notice_text);
};

#endif