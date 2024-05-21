#include "course.h"

Course::Course(std::string i,std::string n , std::string p_n , int cap ,std::string d, std::string t,std::string c_n)
{
    id = i;
    name = n;
    professor_name = p_n;
    capacity = cap;
    class_number = c_n;

    std::stringstream S(d);
    std::string day,month,year;

    getline(S,year,DATE_SEPRATOR);
    getline(S,month,DATE_SEPRATOR);
    getline(S,day,DATE_SEPRATOR);
    
    exam_date = new Date(std::stoi(day),std::stoi(month),std::stoi(year));

    std::stringstream S2(t);
    std::string day_of_week,start_time,end_time;

    getline(S2,day_of_week,DAY_TIME_SEPRATOR);
    getline(S2,start_time,START_END_SEPRATOR);
    getline(S2,end_time,START_END_SEPRATOR);

    class_time = new Class_Time(day_of_week,std::stoi(start_time),std::stoi(end_time));

}

bool Course::is_Interrupt_Course(std::string time)
{
    std::stringstream S(time);
    std::string day_of_week,start_time,end_time;

    getline(S,day_of_week,DAY_TIME_SEPRATOR);
    getline(S,start_time,START_END_SEPRATOR);
    getline(S,end_time,START_END_SEPRATOR);

    if(class_time->is_Interrupt_Time(day_of_week,std::stoi(start_time),std::stoi(end_time)))
        return true;
    return false;
}

bool Course::is_Valid_Id(std::string course_id)
{
    if(id == course_id)
        return true;
    return false;
}

void Course::Print_Info()
{
    std::cout << id << " " << name << " " <<  capacity << " " << professor_name << std::endl;
}

void Course::Print_All_Info()
{
    std::cout << id << " " << name << " " <<  capacity << " " << professor_name << " ";
    class_time->Print();
    std::cout << " ";
    exam_date->Print();
    std::cout << " " << class_number << std::endl;
}

std::string Course::get_Name()
{
    return name;
}

   


