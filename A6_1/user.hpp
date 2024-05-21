#ifndef USER
#define USER

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "exception.hpp"
#include "commands.hpp"
#include "messages.hpp"
#include "UT_post.hpp"
#include "notification.hpp"
#include "unit.hpp"
#include "course.hpp"


const std::string USER_TYPE_1 = "Professor";
const std::string USER_TYPE_2 = "Student";
const std::string USER_TYPE_3 = "Operator";



class User
{
public:
	User(std::string n,std::string i,std::string p);
	User(std::string n,std::string i,std::string m,std::string m_i,std::string p);
	virtual bool is_Valid_Id (std::string i);
	bool is_Valid_Password(std::string p);
	bool is_Professor();
	bool is_Student();
	void Add_Post(UT_Post *post);
	void Connect(User *target);
	virtual void Print_Info() = 0;
	virtual void Print_Page_Info() = 0;
	bool Permision_Check(std::string cmd);
	std::string get_Type();
	std::string get_Major_Id();
	std::string get_Name();
	void Sort_Posts();
	void Print_Post(std::string post_id);
	void Send_Notification(std::string notice_text);
	void Recieve_Notification(Notification* notif);
	void Print_Notifications();
	void Delete_Post(std::string post_id);

protected:	
	bool logged_in;
	std::string user_type;
	std::string name;
	std::string id;
	std::string major_id;
	std::string major;
	std::string password;
	std::vector<std::string> valid_cmds;
	std::vector<UT_Post*> posts;
	std::vector<User*> connection_list;
	std::vector<Course*> courses;
	std::vector<Notification*> notifications;
	int num_of_posts_history;
};

#endif