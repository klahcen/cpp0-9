#include "ClapTrap.hpp"

int  main(){
    ClapTrap claptrap;

    claptrap.attack("target");
    claptrap.attack("target");
    claptrap.attack("target");
    claptrap.takeDamage(12);
    claptrap.attack("target");
    return 0;
}