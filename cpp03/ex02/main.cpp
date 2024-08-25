#include "FragTrap.hpp"

int  main(){
    FragTrap fragtrap("a");
    
    fragtrap.displayStats();
    fragtrap.attack("target");
    fragtrap.attack("target");
    fragtrap.attack("target");
    fragtrap.takeDamage(12);
    fragtrap.highFivesGuys();
    fragtrap.highFivesGuys();
    fragtrap.highFivesGuys();
    fragtrap.displayStats();
    return 0;
}