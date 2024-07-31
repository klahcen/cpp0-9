
#include "Zombie.hpp"

void    Zombie::announce(void)
{
    std::cout << name << " : BraiiiiiiinnnzzzZ..."<<std::endl;
}

Zombie::Zombie()
{

}

void Zombie::setname(std::string namee){
    name = namee;
}
Zombie::~Zombie()
{
    std::cout<<name<<" : is destroyed"<<std::endl;
}