#include "Ice.hpp"

Ice::Ice():AMateria("ice"){
    
}

Ice::Ice(const Ice &other){
    (void)other;
}

Ice& Ice::operator= (const Ice &other){
    (void)other;
    return *this;
}

Ice::~Ice(){
}
AMateria* Ice::clone() const{
    return(new Ice());
}

void* Ice::operator new(size_t size){
    void *p = ::operator new(size);
    floor.liste_add(floor.liste_New(p));
    return p;
}

void Ice::use(ICharacter& target){
    std::cout<<"* shoots an ice bolt at "<<target.getName()<<" *"<<std::endl;
}
