
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(){
    std::cout<<"call the constructors"<<std::endl;
}
DiamondTrap::DiamondTrap(const std::string& name){
    std::cout<<"the constructors called"<<std::endl;
    this->Name = name;
    ClapTrap::Name = name +"_clap_name"; 
    this->Hit_points = FragTrap::Hit_points;
    this->Energy_points = ScavTrap::Energy_points;
    this->Attack_damage = FragTrap::Attack_damage;
}
DiamondTrap::DiamondTrap(const DiamondTrap& other){
    std::cout<<"Copy constructor called"<<std::endl;
    *this = other;
}
DiamondTrap& DiamondTrap::operator= (const DiamondTrap& other){
    std::cout<<"Copy assignment operator called"<<std::endl;
    this->Hit_points= other.Hit_points;
    this->Attack_damage = other.Attack_damage;
    this->Energy_points = other.Energy_points;
    this->Name = other.Name;
    return *this;
}
DiamondTrap::~DiamondTrap(){
    std::cout<<"call the destructor "<<std::endl;
}

void DiamondTrap::whoAmI() {
    std::cout << "DiamondTrap name: " << this->Name << std::endl;
    std::cout << "ClapTrap name: " << ClapTrap::Name << std::endl;
}


void DiamondTrap::displayStats() {
    std::cout << "Hit Points: " << this->Hit_points << std::endl;
    std::cout << "Energy Points: " << this->Energy_points << std::endl;
    std::cout << "Attack Damage: " << this->Attack_damage<< std::endl;
}