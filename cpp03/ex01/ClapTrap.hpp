
#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap{
    protected:
        std::string Name;
        int Hit_points;
        unsigned int Energy_points;
        unsigned int Attack_damage;
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap& other);
        ClapTrap& operator= (const ClapTrap& other);
        ~ClapTrap();
        void attack(const std::string& traget);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif