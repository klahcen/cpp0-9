
#ifndef ZONBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <memory>

class Zombie {
    private:
        std::string name;
    public:
        Zombie();
        ~Zombie();
        void setname(std::string namee);
        void announce(void);
};

Zombie* zombieHorde( int N, std::string name );


#endif