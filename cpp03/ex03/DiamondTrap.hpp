
#ifndef DIAMONDTRAP_HPP
#define  DIAMONDTRAP_HPP

#include "ScavTrap.cpp"
#include "FragTrap.cpp"

class DiamondTrap: public FragTrap, public ScavTrap{
private:
    std::string name;
};
#endif