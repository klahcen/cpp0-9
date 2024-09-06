
#include "Brain.hpp"

Brain::Brain(){
    std::cout<<"call Brain copy Constructors" << std::endl;

}
Brain::Brain(const Brain& other){
    std::cout<<"call Brain copy Constructors" << std::endl;
    for(int i = 0; i < 100; i++)
        this->ideas[i] = other.ideas[i];
}
Brain& Brain::operator= (const Brain& other){
    std::cout<<"call Brain Copy assignment operator" << std::endl;
    for(int i = 0; i < 100; i++)
        this->ideas[i] = other.ideas[i];
    return *this;
}
Brain::~Brain(){
    std::cout<<"call  Brain destructors" << std::endl;
}