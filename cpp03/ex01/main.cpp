#include "ScavTrap.hpp"

int  main(){
    ScavTrap scavtrap;
    // ScavTrap("Robot");
    std::cout<<"=>> "<<scavtrap.gethit()<<" ,"<<scavtrap.getenrge()<<" ,"<<scavtrap.gethit()<<std::endl;
    scavtrap.attack("target");
    scavtrap.attack("target");
    scavtrap.attack("target");
    scavtrap.takeDamage(12);
    scavtrap.attack("target");
    scavtrap.guardGate();
    std::cout<<"=>> "<<scavtrap.gethit()<<" ,"<<scavtrap.getenrge()<<" ,"<<scavtrap.gethit()<<std::endl;
    return 0;
}