
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(){
    std::cout<<"call the default constructor"<<std::endl;
    this->Hit_points = 1000;
    this->Energy_points = 50;
    this->Attack_damage = 20;
}

ScavTrap::ScavTrap(std::string name){
    std::cout<<"constructor called"<<std::endl;
    this->Name = name;
}


ScavTrap::ScavTrap(const ScavTrap& other){
    std::cout<<"Copy constructor called"<<std::endl;
    *this = other;
}

void ScavTrap::guardGate(){
    std::cout<<"That ScavTrap is now in Gate keeper mode"<<std::endl;
}

void ScavTrap::attack(const std::string& target){
    if(this->Hit_points > 0 && this->Energy_points > 0){
        std::cout<<"ScavTrap "<<this->Name<<" attacks "<<target<<", causing "<<this->Attack_damage<<" points of damage!"<<std::endl;
        this->Energy_points--;
    }
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