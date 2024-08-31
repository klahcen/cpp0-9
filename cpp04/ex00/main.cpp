#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const Animal* meta = new Animal();
    // const WrongAnimal* meta = new WrongAnimal();
    // const WrongAnimal* i = new WrongCat();
    const Animal* i = new Cat();
// std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); 
// j->makeSound();
    meta->makeSound();
    delete meta;
    delete i;
// delete j;
return 0;
}