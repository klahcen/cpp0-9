
#include "ClapTrap.hpp"

void ClapTrap::attack(const std::string& target){
    if(this->Hit_points > 0 && this->Energy_points > 0){
        std::cout<<"ClapTrap "<<this->Name<<" attacks "<<target<<", causing "<<this->Attack_damage<<" points of damage!"<<std::endl;
        this->Energy_points--;
    }
}

void ClapTrap::takeDamage(unsigned int amount){
    if(this->Hit_points > 0 && this->Energy_points > 0){
        std::cout<<"ClapTrap "<<this->Name<<" takeDamage "<<amount<<", causing "<<this->Attack_damage<<" points of damage!"<<std::endl;
        this->Hit_points--;
    }
}
void ClapTrap::beRepaired(unsigned int amount){
    if(this->Hit_points > 0 && this->Energy_points > 0){
        std::cout<<"ClapTrap "<<this->Name<<" beRepaired "<<amount<<", causing "<<this->Attack_damage<<" points of damage!"<<std::endl;
        this->Hit_points++;
        this->Energy_points--;
    }
}


ClapTrap::ClapTrap(){
    std::cout<<"call the constructors"<<std::endl;
    this->Attack_damage = 10;
    this->Energy_points = 10;
    this->Attack_damage = 0;
}

ClapTrap::ClapTrap(std::string name){
    this->Name = name;
}
ClapTrap::ClapTrap(const ClapTrap& other){
    *this = other;
}
ClapTrap& ClapTrap::operator= (const ClapTrap& other){
    this->Hit_points= other.Hit_points;
    this->Attack_damage = other.Attack_damage;
    this->Energy_points = other.Energy_points;
    this->Name = other.Name;
    return *this;
}

ClapTrap::~ClapTrap(){
    std::cout<<"call the destructor "<<std::endl;
}
