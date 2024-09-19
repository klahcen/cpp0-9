#ifndef SERIALI_HPP
#define SERIALI_HPP

#include <stdint.h>
#include <iostream>
#include "Data.hpp"

struct Data;
class Serializer
{
    private:
        Serializer();
        Serializer(const Serializer &other);
    public:
        Serializer& operator= (const Serializer &other);
        ~Serializer();
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);

};

#endif