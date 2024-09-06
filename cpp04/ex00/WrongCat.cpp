#include "WrongCat.hpp"

WrongCat::WrongCat(){
    std::cout<<"Call WrongCat defult Constructors"<<std::endl;
    this->type = "WrongCat";
}
WrongCat::WrongCat(const WrongCat& other){
    std::cout<<"Call WrongCat copy Constructors"<<std::endl;
    *this = other;
}
WrongCat& WrongCat::operator= (const WrongCat& other){
    std::cout<<"Call WrongCat Copy assignment operator"<<std::endl;
    this->type = other.type;
    return *this;
}
WrongCat::~WrongCat(){
    std::cout<<"Call WrongCat destructors"<<std::endl;
}
void WrongCat::makeSound(void)  const{
    std::cout<<"sound of WrongCat"<<std::endl;
}