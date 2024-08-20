
#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap{
    private:
        std::string Name;
        unsigned int h;
        unsigned int e;
        unsigned int a;
        void Hit_points(unsigned int h);
        unsigned int  get_Hit_points(void);
        void Energy_points(unsigned int e);
        unsigned int get_Energy_points(void);
        void Attack_damage(unsigned int a);
        unsigned int get_Attack_damage(void);
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