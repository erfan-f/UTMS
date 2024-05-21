#include "date.h"

Date::Date()
{
    day = 1;
    month = 1;
    year = 1;
}


Date::Date(int d , int m , int y)
{
    day = d;
    month = m;
    year = y;
}

void Date::Print()
{
    std::cout << year << DATE_SEPRATOR << month << DATE_SEPRATOR << day;
} 
