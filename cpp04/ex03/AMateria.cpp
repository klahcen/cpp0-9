
#include "AMateria.hpp"

AMateria::AMateria(){
}

AMateria::AMateria(const AMateria &other){
    this->type = other.type;
}

AMateria&  AMateria::operator= (const AMateria &other){
    this->type = other.type;
    return *this;
}

AMateria::AMateria(std::string const & type){
    this->type = type;
}

std::string const & AMateria::getType() const{
    return this->type;
}

void AMateria::use(ICharacter& target){
    std::cout<<"AMateria "<<target.getName()<<std::endl;
}

AMateria::~AMateria(){
}
