
#include "Dog.hpp"

Dog::Dog(){
    std::cout<<"Call Dog defult Constructors"<<std::endl;
    this->brian = new Brain();
    this->type = "Dog";
}
Dog::Dog(const Dog& other){
    std::cout<<"Call Dog copy Constructors"<<std::endl;
    *this = other;
}
Dog& Dog::operator= (const Dog& other){
    std::cout<<"Call Dog copy assignment operator"<<std::endl;
    for(int i=0;i<100;i++)
        this->brian->ideas[i] = other.brian->ideas[i];
    return *this;
}
Dog::~Dog(){
    std::cout<<"Call Dog destructors"<<std::endl;
    delete brian;
}
void Dog::makeSound(void)  const{
    std::cout<<"Sound of Dog"<<std::endl;
}