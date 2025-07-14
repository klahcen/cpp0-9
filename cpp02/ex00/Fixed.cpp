

#include "Fixed.hpp"

Fixed::Fixed(){

    std::cout<<"Default constructor called"<<std::endl;
    this->value =0;
}

Fixed::Fixed(const Fixed& F){
    std::cout<<"Copy constructor called"<<std::endl;
    *this = F;
}

Fixed&  Fixed::operator= (const Fixed& a){
    std::cout<<"Copy assignment operator called"<<std::endl;
    this->value = a.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
    std::cout<<"Destructor called"<<std::endl;
}

int Fixed::getRawBits(void) const{
    std::cout<<"getRawBits member function called"<<std::endl;
    return(value);
}

void Fixed::setRawBits( int const raw ){
    std::cout<<"getRawBits member function called"<<std::endl;
    this->value = raw;
}
