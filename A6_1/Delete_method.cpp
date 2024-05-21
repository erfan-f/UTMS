#include "Delete_method.hpp"

Delete::Delete(std::string t , std::vector <std::string> cmds)
:Method(t,cmds) {}

void Delete::Process_Cmd(std::string cmd_line ,std::vector<Major*> &majors ,std::vector<Unit*> &units ,std::vector<User*> &users ,std::vector<Course*> &courses, User **current_user,bool &user_logged_in)
{
    std::stringstream S(cmd_line);

	std::string temp_str,command;

	S >> temp_str >> command >> temp_str;

    if(command == USER_CMD_TYPE_4)
    {
        std::string id_operator,id;

        S >> id_operator,id;

    }
    else if(command == USER_CMD_TYPE_9)
    {

    }
}
