
#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA{
    private:
        std::string name;
        std::string name1;
    public:
        HumanA(std::string name, Weapon weapon);
        void    attack();
};

#endif