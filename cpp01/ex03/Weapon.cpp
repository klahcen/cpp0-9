
#include "Weapon.hpp"

std::string Weapon::getType()
{
    return (string);
}

void    Weapon::setType(std::string string)
{
    this->string = string;
}

Weapon::Weapon(std::string string)
{
    setType(string);
}