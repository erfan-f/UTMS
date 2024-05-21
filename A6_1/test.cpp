#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include "UT_post.h"


bool CompareByid(const UT_Post *a ,const UT_Post *b);

enum week 
{
    Saturday,Sunday,Monday,Tuesday,Wednesday
};

int main()
{
    std::string str = "message \"Hello to you my dear dear friend\" title";
    std::string opr;
    std::stringstream S(str);

    int x = str.find('"');
    std::string str1;
    str1 = str.erase(0,x+1);

    int y= str.find('"');
    std::string str2 = str1.substr(0,y);
    S >> opr;

    std::string final = '"' + str2 + '"';


    std::cout << str2 << std::endl;

    return 0;
}


