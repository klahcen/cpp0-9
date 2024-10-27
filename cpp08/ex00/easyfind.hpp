#ifndef ESAYFIND_HPP
#define ESAYFIND_HPP

#include <iostream>
#include <algorithm>

template <class T>
void easyfind(T type, int nbr)
{
    if(std::find(type.begin(), type.end(), nbr) != type.end())
    {
        std::cout<< "Element Found at Position: " 
        <<(std::find(type.begin(), type.end(), nbr) ;//- type.begin() + 1)
        <<std::endl;
    }
    else
        throw std::runtime_error("Error");
}

#endif
