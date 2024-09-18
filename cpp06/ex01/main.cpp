
#include "Serialization.hpp"


int main() {
    Data data;
    data.id = 42;
    data.name = "Example";

    Data* originalPtr = &data;

    // Serialize the pointer
    uintptr_t raw = Serializer::serialize(originalPtr);

    // Deserialize back to a pointer
    Data* deserializedPtr = Serializer::deserialize(raw);

    // Check if they are the same
    if (originalPtr == deserializedPtr) {
        std::cout << "Success: Pointers are equal." << std::endl;
    } else {
        std::cout << "Error: Pointers are not equal." << std::endl;
    }

    return 0;
}

// int main()
// {
//     Data *I=new Data();
//     Data *K = new Data();
//     Serialization s;
//     Deserialize D;
//     uintptr_t ptr;
    
//     I->i=21;
//     I->c='k';
//     I->s="lahcen";
//     I->f = 1337.90f;
//     I->d = 1221.122;
    
//     ptr = s.serialize(I);
//     K = D.deserialize(ptr);
    
//     std::cout
//     <<"int: "<<K->i<<std::endl
//     <<"char: "<<K->c<<std::endl
//     <<"string: "<<K->s<<std::endl
//     <<"float: "<<K->f<<std::endl
//     <<"double: "<<K->d<<std::endl;

//     delete I;
//     delete K;

//     return 0;
// }