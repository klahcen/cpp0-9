
#include "ClapTrap.hpp"

void ClapTrap::Hit_points(unsigned int h){
    this->h = h;
}

void ClapTrap::Energy_points(unsigned int e){
    this->e = e;
}

void ClapTrap::Attack_damage(unsigned int a){
    this->a = a;
}

unsigned int  ClapTrap::get_Hit_points(void){
    return this->h;
}

unsigned int ClapTrap::get_Energy_points(void){
    return this->e;
}

unsigned int ClapTrap::get_Attack_damage(void){
    return this->a;
}

void ClapTrap::attack(const std::string& target){
    std::cout<<"ClapTrap "<<this->Name<<" attacks "<<target<<", causing "<<this->a<<" points of damage!"<<std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){

}
void ClapTrap::beRepaired(unsigned int amount){

}


ClapTrap::ClapTrap(){
    std::cout<<"call the constructors"<<std::endl;
}

ClapTrap::ClapTrap(std::string name){
    this->Name = name;
}
ClapTrap::ClapTrap(const ClapTrap& other){
    *this = other;
}
ClapTrap& ClapTrap::operator= (const ClapTrap& other){
    this->a = other.a;
    this->h = other.h;
    this->e = other.e;
    this->Name = other.Name;
    return *this;
}

ClapTrap::~ClapTrap(){
    std::cout<<"call the destructor "<<std::endl;
}
