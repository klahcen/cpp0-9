
#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal{
    private:
    public:
        Brain *brain;
        Dog();
        Dog(const Dog& other);
        Dog& operator= (const Dog& other);
        void makeSound(void)  const;
        ~Dog();
};

#endif 