
#include "Dog.hpp"

Dog::Dog(){
    std::cout<<"Call Dog defult Constructors"<<std::endl;
    this->type = "Dog";
}
Dog::Dog(const Dog& other){
    std::cout<<"Call Dog copy Constructors"<<std::endl;
    *this = other;
}
Dog& Dog::operator= (const Dog& other){
    std::cout<<"Call Dog copy assignment operator"<<std::endl;
    this->type = other.type;
    return *this;
}
Dog::~Dog(){
    std::cout<<"Call Dog destructors"<<std::endl;
}
void Dog::makeSound(void)  const{
    std::cout<<"Sound of Dog"<<std::endl;
}