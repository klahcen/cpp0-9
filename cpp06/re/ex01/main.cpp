
#include "Serializer.hpp"


int main() {
    Data data;
    
    data.c = 'l';
    data.i = 1337;
    data.f = 10.24f;
    data.d = 4557.22;
    data.name = "lahcen";

    Data* originalPtr = &data;

    uintptr_t raw = Serializer::serialize(originalPtr);
    Data* deserializedPtr = Serializer::deserialize(raw);

    if (deserializedPtr)
    {
        if (originalPtr == deserializedPtr)
            std::cout << "Success: Pointers are equal." << std::endl;
        else
            std::cout << "Error: Pointers are not equal." << std::endl;
    }

    return 0;
}