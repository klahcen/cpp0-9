
#include "ScavTrap.hpp"


ScavTrap::ScavTrap(){
     std::cout<<"call the constructors"<<std::endl;
    this->Hit_points = 100;
    this->Energy_points = 50;
    this->Attack_damage = 20;
}

ScavTrap::ScavTrap(std::string name){
    std::cout<<"constructor called"<<std::endl;
    this->Name = name;
}

int ScavTrap::gethit(void){
    return (this->Hit_points);
}

int ScavTrap::gedamge(void){ 
    return(this->Energy_points);
}

int ScavTrap::getenrge(void){
    return  this->Attack_damage;
}

void ScavTrap::guardGate(){
    std::cout<<"That ScavTrap is now in Gate keeper mode"<<std::endl;
}

void ScavTrap::attack(const std::string& target){
    std::cout<<"ClapTrap "<<this->Name<<" attacks "<<target<<", causing "<<this->Attack_damage<<" points of damage!"<<std::endl;
}

ScavTrap& ScavTrap::operator= (const ScavTrap& other){
    std::cout<<"Copy assignment operator called"<<std::endl;
    this->Hit_points= other.Hit_points;
    this->Attack_damage = other.Attack_damage;
    this->Energy_points = other.Energy_points;
    this->Name = other.Name;
    return *this;
}

ScavTrap::~ScavTrap(){
    std::cout<<"call the destructor "<<std::endl;
}