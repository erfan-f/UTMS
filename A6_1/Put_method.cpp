#include "Put_method.hpp"


Put::Put(std::string t , std::vector <std::string> cmds)
:Method(t,cmds) {}

void Put::Process_Cmd(std::string cmd_line ,std::vector<Major*> &majors ,std::vector<Unit*> &units ,std::vector<User*> &users ,std::vector<Course*> &courses, User **current_user,bool &user_logged_in)
{
    std::stringstream S(cmd_line);

	std::string temp_str , command;

	S >> temp_str;
	S >> command;
	S >> temp_str;

    if(command == USER_CMD_TYPE_9)
    {
        std::string id_operator,id;
        S >> id_operator >> id;

        if(stoi(id) <= 0)
            throw CommandException(ERROR_1);

        Course *target_course;
        target_course = Take_A_Course(courses,id);

        Student *student = dynamic_cast<Student*>(*current_user);
        if(student == NULL)
            throw CommandException(ERROR_3);

        if(!student->is_Allowed_to_Take(target_course))
            throw CommandException(ERROR_3);
        
        std::cout << DONE_MESSAGE << std::endl;
    }

}

Course* Put::Take_A_Course(std::vector<Course*> courses,std::string course_id)
{
    bool id_validation = false;
    Course* course;
    for(int i=0 ; i<courses.size() ; i++)
    {
        if(courses[i]->is_Valid_Id(course_id))
        {
            id_validation = true;
            course = courses[i];
            break;
        }
    }
    if(!id_validation)
        throw CommandException(ERROR_2);

    return course;
}