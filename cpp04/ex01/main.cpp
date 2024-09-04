#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
const Animal* j = new Dog();
const Animal* i = new Cat();
Animal* ii = new Cat();
*ii = *i;
ii->makeSound();
delete j;//should not create a leak
delete i;
delete ii;
return 0;
}