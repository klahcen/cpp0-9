
#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal{
    private:
        Brain *brian;
    public:
        Dog();
        Dog(const Dog& other);
        Dog& operator= (const Dog& other);
        void makeSound(void)  const;
        ~Dog();
};

#endif 