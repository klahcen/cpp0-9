
#include "Animal.hpp"

AAnimal::AAnimal(){
    std::cout<<"call AAnimal defult Constructors" << std::endl;
    this->type = "AAnimal";
}
AAnimal::AAnimal(const AAnimal& other){
    std::cout<<"call AAnimal copy Constructors" << std::endl;
    *this = other;
}
AAnimal& AAnimal::operator= (const AAnimal& other){
    std::cout<<"call AAnimal Copy assignment operator" << std::endl;
    this->type = other.type;
    return *this;
}
AAnimal::~AAnimal(){
    std::cout<<"call AAnimal destructors" << std::endl;
}
std::string AAnimal::getType() const {
    return this->type;
}
