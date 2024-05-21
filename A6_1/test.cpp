#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include "UT_post.hpp"


bool CompareByid(const UT_Post *a ,const UT_Post *b);

enum week 
{
    Saturday,Sunday,Monday,Tuesday,Wednesday
};

int main()
{
    std::string str = "hello fkldsmfkl  kdslfdsklf               skldgkldsfkl";

    std::stringstream S(str);

    std::string name,str2;

    S >> name;
    S >> str2;

    std::cout << name << std::endl;
    return 0;
}


