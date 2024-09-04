
#include "Cat.hpp"

Cat::Cat(){
    std::cout<<"Call cat defult Constructors"<<std::endl;
    this->brain = new Brain();
    this->type = "Cat";
}
Cat::Cat(const Cat& other){
    std::cout<<"Call cat copy Constructors"<<std::endl;
    for(int i= 0 ; i < 100; i++)
        this->brain->ideas[i] = other.brain->ideas[i];
    this->type = other.type;
}
Cat& Cat::operator= (const Cat& other){
    std::cout<<"Call cat Copy assignment operator"<<std::endl;
    Cat *cat = new Cat();
    for(int i= 0 ; i < 100; i++)
        cat->brain->ideas[i] = other.brain->ideas[i];
    cat->type = other.type;
    return *cat;
}
Cat::~Cat(){
    std::cout<<"Call cat destructors"<<std::endl;
    delete brain;
}
void Cat::makeSound(void)  const{
    std::cout<<"sound of Cat"<<std::endl;
}

