#include "ScavTrap.hpp"

int  main(){
    ScavTrap scavtrap("a");
   
    scavtrap.displayStats();
    scavtrap.attack("target");
    scavtrap.attack("target");
    scavtrap.attack("target");
    scavtrap.takeDamage(12);
    scavtrap.attack("target");
    scavtrap.displayStats();
   return 0;
}