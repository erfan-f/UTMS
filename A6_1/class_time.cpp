#include "class_time.hpp"

Class_Time::Class_Time()
{
    start = -1;
    end = -1;
    day = ""; 
}


Class_Time::Class_Time(std::string day_of_week , int s , int e)
{
    start = s;
    end = e;
    day = day_of_week;
}

bool Class_Time::is_Interrupt_Time(std::string day_of_week , int start_time , int end_time)
{
    if(day == day_of_week)
    {
        if(!(start_time >= end || end_time <= start))
            return true;
        return false;
    }
    else
        return false;
}

void Class_Time::Print()
{
    std::cout << day << DAY_TIME_SEPRATOR << start << START_END_SEPRATOR << end;
}

std::string Class_Time::get_Day()
{
    return day;
}
int Class_Time::get_Start()
{
    return start;
}
int Class_Time::get_End()
{
    return end;
}
