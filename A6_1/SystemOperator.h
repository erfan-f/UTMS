#ifndef SYSTEMOP
#define SYSTEMOP

#include "user.h"


class SystemOperator : public User
{
public:
    SystemOperator(std::string n , std::string i , std::string pass);
    void Print_Info();
    void Print_Page_Info();

};

#endif
