
#include "Dog.hpp"

Dog::Dog(){
    std::cout<<"Call Dog defult Constructors"<<std::endl;
    this->brain  = new Brain();
    this->type = "Dog";
}
Dog::Dog(const Dog& other){
    std::cout<<"Call Dog copy Constructors"<<std::endl;
    brain = new Brain();
    for(int i=0; i< 100; i++)
        this->brain->ideas[i] = other.brain->ideas[i];
    this->type = other.type;
}
Dog& Dog::operator= (const Dog& other){
    std::cout<<"Call Dog copy assignment operator"<<std::endl;
    if(this != &other)
    {
        if(this->brain  != NULL)
            delete this->brain;
        this->brain  = new Brain();
        for(int i = 0; i < 100; i++)
            brain->ideas[i] = other.brain->ideas[i];
        this->type = other.type;
    }
    return *this;
}
Dog::~Dog(){
    std::cout<<"Call Dog destructors"<<std::endl;
    delete brain;
}
void Dog::makeSound(void)  const{
    std::cout<<"Sound of Dog"<<std::endl;
}