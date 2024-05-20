#ifndef DATE
#define DATE

const char DATE_SEPRATOR = '/';

class Date
{
public:
    Date();
    Date(int d , int m , int y);

private:
    int day;
    int month;
    int year;

};

#endif