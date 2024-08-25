
#include "FragTrap.hpp"

FragTrap::FragTrap(){
    std::cout<<"The default constructor called"<<std::endl;
    this->Hit_points = 100;
    this->Energy_points = 100;
    this->Attack_damage = 30;
}

FragTrap::FragTrap(std::string name){
    std::cout<<"The constructor called"<<std::endl;
    this->Name = name;
}

FragTrap::FragTrap(const FragTrap& other){
    std::cout<<"The copy constructor called"<<std::endl;
    *this = other;
}

FragTrap& FragTrap::operator= (const FragTrap& other){
    std::cout<<"The copy assignment operator called"<<std::endl;
    this->Hit_points = other.Hit_points;
    this->Energy_points = other.Energy_points;
    this->Attack_damage = other.Attack_damage;
    return *this;
}

FragTrap::~FragTrap(){
    std::cout<<"Destructor called"<<std::endl;
}

void FragTrap::highFivesGuys(void){
    std::cout<<"high fives request"<<std::endl;
}