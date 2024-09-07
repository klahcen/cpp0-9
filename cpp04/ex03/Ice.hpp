
#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "garbage_collector.hpp"

class Ice: public AMateria {
    public :
        Ice();
        Ice(const Ice &other);
        Ice& operator= (const Ice &other);
        void* operator new(size_t size);
        ~Ice();
        void use(ICharacter& target);
        AMateria* clone() const;
};

#endif