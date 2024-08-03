
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon Weapon)
{
    this->name = name;
}
void    HumanA::attack()
{
    std::cout << name << " attacks with their "<<std::endl;
}