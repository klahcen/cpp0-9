#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal{
    public:
        WrongCat();
        WrongCat(const WrongCat& other);
        WrongCat& operator= (const WrongCat& other);
        void makeSound(void)  const;
        ~WrongCat();
};
#endif