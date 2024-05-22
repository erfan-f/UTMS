#include "class_time.hpp"

Class_Time::Class_Time()
{
    start = -1;
    end = -1;
}


Class_Time::Class_Time(Week day_of_week , int s , int e)
{
    start = s;
    end = e;
    day = day_of_week;
}

bool Class_Time::is_Interrupt_Time(Week day_of_week , int start_time , int end_time)
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
    std::cout << Day_To_String(day) << DAY_TIME_SEPRATOR << start << START_END_SEPRATOR << end;
}

Week Class_Time::get_Day()
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

std::string Class_Time::Day_To_String(Week day)
{
    if(day == Saturday)
        return "Saturday";
    else if(day == Sunday)
        return "Sunday";
    else if(day == Monday)
        return "Monday";
    else if(day == Tuesday)
        return "Tuesday";
    else if(day == Wednesday)
        return "Wednesday";   
    return "";
}