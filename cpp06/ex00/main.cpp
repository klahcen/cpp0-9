#include "ScalarConverter.hpp"
#include <iostream>
#include <string>

int main(int ac, char **av)
{
    ScalarConverter s;
    if(ac == 2)
    {
        std::string str(av[1]);
        s.convert(str);
    }
    else
        std::cout<<"bad argiment"<<std::endl;
}
