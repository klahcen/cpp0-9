
#include "HumanB.hpp"
#include <string>

void    HumanB::setWeapon(Weapon& club)
{
    this->weapon = &club;
}

HumanB::HumanB(std::string name){
    this->name = name;
}

void    HumanB::attack()
{
    if(weapon)
        std::cout << name << " attacks with their "<<weapon->getType()<<std::endl;
    else
        std::cout << name << "has no weapon to attack with."<<std::endl;
}