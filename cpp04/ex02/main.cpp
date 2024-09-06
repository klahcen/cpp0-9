#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    // AAnimal *aanimal = new AAnimal();
const AAnimal* j = new Dog();
const AAnimal* i = new Cat();
AAnimal* ii=new Cat();
*ii = *i;
i->b
ii->makeSound();
delete j;//should not create a leak
delete i;
delete ii;
// delete aanimal;
return 0;
}