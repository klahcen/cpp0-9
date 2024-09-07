#include "Cure.hpp"
Cure::Cure():AMateria("cure"){
}

Cure::Cure(const Cure &other){
   (void)other;
}

Cure& Cure::operator= (const Cure &other){
    (void)other;
    return *this;
}

Cure::~Cure(){
}

AMateria* Cure::clone() const{
    return (new Cure());
}

void* Cure::operator new(size_t size){
    void *p = ::operator new(size);
    floor.liste_add(floor.liste_New(p));
    return p;
}

void Cure::use(ICharacter& target){
    std::cout<< "* heals "<<target.getName()<<"’s wounds *"<<std::endl;
}