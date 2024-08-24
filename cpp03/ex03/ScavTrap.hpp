#ifndef ScavTrap_HPP
#define ScavTrap_HPP

#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap{

    public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap& operator= (const ScavTrap& other);
        int  gethit(void);
        int  gedamge(void);
        int  getenrge(void);
        void guardGate();
        void attack(const std::string& target);
        ~ScavTrap();
};

#endif