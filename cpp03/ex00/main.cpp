#include "ClapTrap.hpp"

int  main(){
    ClapTrap claptrap("aaa");
    claptrap.attack("target");
    claptrap.attack("target");
    claptrap.displayStats();
    claptrap.attack("target");
    claptrap.displayStats();
    claptrap.attack("target");
    claptrap.attack("target");
    claptrap.attack("target");
    claptrap.attack("target");
    claptrap.attack("target");
    claptrap.attack("target");
    claptrap.attack("target");
    claptrap.attack("target");
    claptrap.attack("target");
    claptrap.takeDamage(12);
    claptrap.attack("target");
    claptrap.displayStats();
    return 0;
}