#ifndef CLASS_TIME
#define CLASS_TIME

#include <iostream>

enum day_of_week 
{
    Saturday,Sunday,Monday,Tuesday,Wednesday
};

const char DAY_TIME_SEPRATOR = ':';
const char START_END_SEPRATOR = '-';

class Class_Time
{
public:
    Class_Time();
    Class_Time(std::string day_of_week , int s , int e);
    bool is_Interrupt_Time(std::string day_of_week , int start_time , int end_time);
private:
    int start;
    int end;
    std::string day;
};

#endif