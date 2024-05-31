#ifndef UT_POST
#define UT_POST

#include <string>
#include <vector>
#include <sstream>
#include "messages.hpp"


class UT_Media
{
public:

	UT_Media(std::string i,std::string t,std::string m);
	std::string get_Info();
	virtual std::string get_All_Info() = 0;
	void set_Id(std::string i);
	bool is_Valid_Id(std::string target_id);
	bool Compare_Id(UT_Media *target_post);

protected:
	std::string id;
	std::string title;
	std::string message;
};

class UT_Post : public UT_Media
{
public:
	UT_Post(std::string i,std::string t,std::string m,std::string im_p);
	std::string get_All_Info();


private:
	std::string image_path;

};

class TA_Form : public UT_Media
{
public:
	TA_Form(std::string i,std::string t,std::string m,std::string c_i,std::string c_info);
	void Add_TA_Request(std::string student_id);
	std::string get_All_Info();
	std::string get_Course_Id();

private:
	std::string course_id;
	std::string course_information;
	std::vector<std::string> volunteers;
};

#endif