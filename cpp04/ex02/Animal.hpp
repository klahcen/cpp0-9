
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class AAnimal{
    protected: 
        std::string type;
    public:
        AAnimal();
        AAnimal(const AAnimal& other);
        AAnimal& operator= (const AAnimal& other);
        virtual void makeSound(void) const=0;
        std::string getType() const;
        virtual ~AAnimal();

};

#endif