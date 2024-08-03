#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon{
    private:
        std::string string;
    public:
		Weapon(std::string string);
        std::string getType();
        void setType(std::string string);
};


#endif