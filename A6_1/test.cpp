#include <iostream>
#include <string>
#include <sstream>



enum week 
{
    Saturday,Sunday,Monday,Tuesday,Wednesday
};

int main()
{
    std::string str = "1403/8/4";

    std::stringstream S(str);
    std::string day;

    getline(S,day,'/');
        getline(S,day,'/');



    std::cout << day << std::endl;
    return 0;
}