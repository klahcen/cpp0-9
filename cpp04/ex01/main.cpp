#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
const Animal* meta = new Animal();
// const Animal* j = new Dog();
const Animal* i = new Cat();
 Animal* ii = new Cat();
*ii = *i;
// std::cout << j->getType() << " " << std::endl;
// std::cout << i->getType() << " " << std::endl;
ii->makeSound(); 
// j->makeSound();
// meta->makeSound();

delete meta;
delete i;
// delete j;
delete ii;
return 0;
}