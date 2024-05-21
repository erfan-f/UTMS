#ifndef COURSE
#define COURSE

#include <iostream>
#include <sstream>
#include <string>
#include "class_time.h"
#include "date.h"

class Course
{
public:
    Course(std::string i,std::string n , std::string p_n , int cap ,std::string d, std::string t,std::string c_n);
    bool is_Interrupt_Course(std::string time);
    bool is_Valid_Id(std::string course_id);
    void Print_Info();
    void Print_All_Info();
    std::string get_Name();

private:
    std::string id;
    std::string name;
    std::string professor_name;
    std::string class_number;
    int capacity;
    Date *exam_date;
    Class_Time *class_time;
};

#endif