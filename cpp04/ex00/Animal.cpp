
#include "Animal.hpp"

Animal::Animal(){
    std::cout<<"call Animal defult Constructors" << std::endl;
    this->type = "Animal";
}
Animal::Animal(const Animal& other){
    std::cout<<"call Animal copy Constructors" << std::endl;
    *this = other;
}
Animal& Animal::operator= (const Animal& other){
    std::cout<<"call Animal Copy assignment operator" << std::endl;
    this->type = other.type;
    return *this;
}
Animal::~Animal(){
    std::cout<<"call Animal destructors" << std::endl;
}
std::string Animal::getType() const {
    return this->type;
}

void Animal::makeSound(void)  const{
    std::cout<<"Sound of Aniaml"<<std::endl;
}

WrongAnimal::WrongAnimal(){
    std::cout<<"call WrongAnimal defult Constructors" << std::endl;
    this->type = "WrongAnimal";
}
WrongAnimal::WrongAnimal(const WrongAnimal& other){
    std::cout<<"call WrongAnimal copy Constructors" << std::endl;
    *this = other;
}
WrongAnimal& WrongAnimal::operator= (const WrongAnimal& other){
    std::cout<<"call WrongAnimal Copy assignment operator" << std::endl;
    this->type = other.type;
    return *this;
}
WrongAnimal::~WrongAnimal(){
    std::cout<<"call WrongAnimal destructors" << std::endl;
}
std::string WrongAnimal::getType() const {
    return this->type;
}

void WrongAnimal::makeSound(void)  const{
    std::cout<<"Sound of Aniaml"<<std::endl;
}

