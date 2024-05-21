#include "user.h"

User::User(std::string n,std::string i,std::string p)
{
	name = n;
	id = i;
	password = p;
	logged_in = false;
}

User::User(std::string n,std::string i,std::string m,std::string m_i,std::string p)
{
	name = n;
	id = i;
	major_id = m_i;
	major = m;
	password = p;
	logged_in = false;
}

bool User::is_Valid_Id(std::string i)
{
	if(id == i)
		return true;
	return false;
}

bool User::is_Valid_Password(std::string p)
{
	if(password == p)
		return true;
	return false;
}

void User::Add_Post(UT_Post *post)
{
	post->id = std::to_string(posts.size() + 1);
	posts.push_back(post);
}

void User::Connect(User *target)
{
	for(int i=0 ; i<connection_list.size() ; i++)
	{
		if(connection_list[i] == target)
			throw CommandException(ERROR_1);
	}
	connection_list.push_back(target);
}

bool User::Permision_Check(std::string cmd)
{
	for(int i=0 ; i<valid_cmds.size(); i++)
	{
		if(cmd == valid_cmds[i])
			return true;
	}
	return false;
}


bool User::is_Professor()
{
	if(user_type == USER_TYPE_1)
		return true;
	return false;
}

bool User::is_Student()
{
	if(user_type == USER_TYPE_2)
		return true;
	return false;
}

std::string User::get_Type()
{
	return user_type;
}

std::string User::get_Major_Id()
{
	return major_id;
}

std::string User::get_Name()
{
	return name;
}

void User::Sort_Posts()
{
	UT_Post *temp;
	for(int i=0 ; i<posts.size() ; i++)
	{
		for(int j=0 ; j<posts.size() -1 ; j++)
		{
			if(posts[j]->id < posts[j+1]->id)
			{
				temp = posts[j];
				posts[j] = posts[j+1];
				posts[j+1] = temp;
			}
		}
	}
}

void User::Print_Post(std::string post_id)
{
	UT_Post *post;
	bool id_validation = false;

	for(int i=0 ; i<posts.size() ; i++)
	{
		if(posts[i]->id == post_id)
		{
			id_validation = true;
			post = posts[i];
			break;
		}
	}
	if(!id_validation)
		throw CommandException(ERROR_2);
	this->Print_Info();
	std::cout << post->id << " " << post->title << " " << post->message << std::endl;
}
