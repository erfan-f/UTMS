#include "course.h"

Course::Course(std::string i,std::string n , std::string p_i , int cap ,std::string d, std::string t,std::string c_n)
{
    id = i;
    name = n;
    professor_id = p_i;
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
