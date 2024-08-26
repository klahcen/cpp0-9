
#include "Cat.hpp"

Cat::Cat(){
    std::cout<<"Call cat defult Constructors"<<std::endl;
    this->type = "Cat";
}
Cat::Cat(const Cat& other){
    std::cout<<"Call cat copy Constructors"<<std::endl;
    *this = other;
}
Cat& Cat::operator= (const Cat& other){
    std::cout<<"Call cat Copy assignment operator"<<std::endl;
    this->type = other.type;
    return *this;
}
Cat::~Cat(){
    std::cout<<"Call cat destructors"<<std::endl;
}
void Cat::makeSound(void)  const{
    std::cout<<"sound of Cat"<<std::endl;
}
