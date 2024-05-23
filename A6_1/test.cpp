#include <iostream>
#include <string>
#include <vector>
#include <sstream>


int main()
{
    std::vector <std::string> s;

    std::ostringstream os;

    os<< "hello"  << '/' << "sdfsfd" << '/' ;
    std::cout << os.str(); 
}