#include "Cure.hpp"

Cure::Cure(){
}

Cure::Cure(const Cure &other){
    this->type = other.type;
}

Cure& Cure::operator= (const Cure &other){
    this->type = other.type;
    return *this;
}

Cure::~Cure(){
}

void Cure::use(ICharacter& target){
    std::cout<< "* heals "<<this->type<<"’s wounds *"<<std::endl;
}