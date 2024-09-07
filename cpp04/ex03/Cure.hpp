#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "garbage_collector.hpp"
class Cure: public AMateria{
    public:
        Cure();
        Cure(const Cure &other);
        Cure& operator= (const Cure &other);
        void* operator new(size_t size);
        ~Cure();
        void use(ICharacter& target);
        AMateria* clone() const;
};

#endif