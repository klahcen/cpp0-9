#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <memory>

class Zombie {
    private:
        std::string name;
    public:
        Zombie(std::string namee);
        void announce(void);
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif 