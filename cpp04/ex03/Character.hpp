#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "garbage_collector.hpp"
class Character: public ICharacter {
    private:
        AMateria* slots[4];
        std::string type;
    public:
        Character();
        Character(std::string const &type);
        Character(const Character &other);
        Character& operator= (const Character &other);
        ~Character();
        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);

};

#endif