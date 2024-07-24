
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP


#include "Contact.hpp"

class Phonebook
{
    public:
        Contact contact[8];
        void    Add(int nbr);
        void    Search(int nbr);
        int     nbr;
};

#endif
