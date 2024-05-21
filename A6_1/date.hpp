#ifndef DATE
#define DATE

#include "iostream"

const char DATE_SEPRATOR = '/';

class Date
{
public:
    Date();
    Date(int d , int m , int y);
    void Print();
    bool is_Equal_Date(Date* date);

private:
    int day;
    int month;
    int year;

};

#endif