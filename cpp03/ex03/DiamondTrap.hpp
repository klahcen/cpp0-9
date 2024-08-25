
#ifndef DIAMONDTRAP_HPP
#define  DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap{
private:
    std::string Name;
public:
    DiamondTrap();
    DiamondTrap(const std::string& name);
    DiamondTrap(const DiamondTrap& other);
    DiamondTrap& operator= (const DiamondTrap& other);
    ~DiamondTrap();
    void whoAmI();
    void displayStats();
};
#endif