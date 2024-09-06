#include "Ice.hpp"

Ice::Ice(){
}

Ice::Ice(const Ice &other){
    this->type = other.type;
}

Ice& Ice::operator= (const Ice &other){
    this->type = other.type;
    return *this;
}

Ice::~Ice(){
}

void Ice::use(ICharacter& target){
    std::cout<<"* shoots an ice bolt at "<<target.getName()<<" *"<<std::endl;
}
