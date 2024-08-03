#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB{
    private:
        std::string name;
        std::string name1;
     public:
        HumanB(std::string name);
        void    attack();
        void    setWeapon(Weapon club);
};

#endif