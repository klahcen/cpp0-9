
#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->name = name;
}
void    HumanB::attack()
{
    std::cout << name << " attacks with their "<<name1<<std::endl;
}
void    HumanB::setWeapon(Weapon club)
{
    this->name1 = club.getType();
}