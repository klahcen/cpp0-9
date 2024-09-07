#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
    private:
        AMateria* materia[4];
    public:
        MateriaSource();
        MateriaSource(const MateriaSource &other);
        MateriaSource& operator= (const MateriaSource &other);
        ~MateriaSource();
        void learnMateria(AMateria* other_m);
        AMateria* createMateria(std::string const & type);
};

#endif