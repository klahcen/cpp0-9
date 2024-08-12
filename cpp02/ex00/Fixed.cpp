

#include "Fixed.hpp"

Fixed::Fixed(){

    std::cout<<"Default constructor called"<<std::endl;
    this->nbr =0;
}

Fixed::Fixed(const Fixed& F){
    std::cout<<"Copy constructor called"<<std::endl;
}

Fixed& Fixed::operator=(Fixed&){
    std::cout<<"Copy assignment operator called"<<std::endl;
}

Fixed::~Fixed()
{
    std::cout<<"Destructor called"<<std::endl;
}

int Fixed::getRawBits(void){
    std::cout<<"getRawBits member function called"<<std::endl;
}

void Fixed::setRawBits( int const raw ){
    std::cout<<"getRawBits member function called"<<std::endl;
}
