#ifndef ScavTrap_HPP
#define ScavTrap_HPP

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap{

    public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap& other);
        ScavTrap& operator= (const ScavTrap& other);
        void guardGate();
        void attack(const std::string& target);
        ~ScavTrap();
};

#endif