
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