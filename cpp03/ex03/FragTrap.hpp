

#ifndef FRAGTRAP_HPP
#define  FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap{
    protected :
        int Hit_points;
        unsigned int Attack_damage;
    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(const FragTrap& other);
        FragTrap& operator= (const FragTrap& other);
        ~FragTrap();
        void highFivesGuys(void);
};

#endif