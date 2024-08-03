
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon weapon)
{
    this->name = name;
    this->name1 = weapon.getType();
}
void    HumanA::attack()
{
    std::cout << name << " attacks with their "<<name1<<std::endl;
}