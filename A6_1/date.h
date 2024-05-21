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

private:
    int day;
    int month;
    int year;

};

#endif