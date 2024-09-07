#include "Character.hpp"

Character::Character(){
    for(int i=0;i<4;i++)
        this->slots[i] = NULL;
}

Character::Character(std::string const &type){
    for(int i=0 ;i<4 ;i++)
        this->slots[i] = NULL;
    this->type = type;
}

Character::Character(const Character &other){
    *this = other;
}
 std::string type;
Character& Character::operator= (const Character &other){
   if(this != &other)
   {
        for(int i=0; i<4; i++)
        {
            if(this->slots[i]!=NULL)
            {
                delete this->slots[i];
                this->slots[i] = NULL;
            }
        }
        for(int i=0; i<4; i++)
        {
            if(other.slots[i] != NULL)
            {
                this->slots[i] = other.slots[i]->clone();
                floor.liste_remove(this->slots[i]);
            }
            else
                this->slots[i] = NULL;
        }
        this->type = other.type;
   }
    return *this;
}

Character::~Character()
{
    for(int i=0; i<4; i++)
    {
        if(this->slots[i]!=NULL)
        {
            delete this->slots[i];
            this->slots[i] = NULL;
        }
    }    
}

std::string const & Character::getName() const{
    return this->type;
}

void Character::equip(AMateria* m)
{
    //check
    if(floor.liste_check(m))
    {
        for(int i=0; i<4 ;i++)
        {
            if(this->slots[i]==NULL)
            {
                this->slots[i] = m;
                floor.liste_remove(m);
                break;
            }
        }
    }
}

void Character::unequip(int idx){
    if(idx>=0 && idx<4)
    {
        floor.liste_add(floor.liste_New(this->slots[idx]));
        this->slots[idx] = NULL;
    }
}
void Character::use(int idx, ICharacter& target){
    if(idx>=0 && idx<4)
    {
        if(this->slots[idx] != NULL)
            this->slots[idx]->use(target);
    }
}