
#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){
    for(int i=0; i<4; i++)
        this->materia[i]=NULL;
}
MateriaSource::MateriaSource(const MateriaSource &other){
    *this = other;
}
MateriaSource& MateriaSource::operator= (const MateriaSource &other){
    if(this != &other)
    {
        for(int i=0; i<4; i++)
        {
            if(this->materia[i]!=NULL)
            {
                delete this->materia[i];
                this->materia[i] = NULL;
            }
        }
        for(int i=0; i<4; i++)
        {
            if(other.materia[i] != NULL)
            {
                this->materia[i] = other.materia[i]->clone();
                floor.liste_remove(this->materia[i]);
            }
            else
                this->materia[i] = NULL;
        }
    }
    return *this;
}
MateriaSource::~MateriaSource(){
    for(int i=0; i<4; i++)
    {
        if(this->materia[i]!=NULL)
        {
            delete this->materia[i];
            this->materia[i] = NULL;
        }
    } 
    
}
void MateriaSource::learnMateria(AMateria* other_m){
    for(int i=0; i<4; i++)
    {
        if(this->materia[i]==NULL)
        {
            this->materia[i] = other_m->clone();
            floor.liste_remove(this->materia[i]);
            break;
        }
    }
}
AMateria* MateriaSource::createMateria(std::string const & type){
    if(type == "cure" || type == "ice")
    {
        for(int i=0; i<4; i++)
        {
            if(this->materia[i] && type == this->materia[i]->getType())
                return (this->materia[i]->clone());
        }
    }
    return NULL;
}
