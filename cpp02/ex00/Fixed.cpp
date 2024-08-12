

#include "Fixed.hpp"

Fixed::Fixed(){

    std::cout<<"Default constructor called"<<std::endl;
    this->nbr =0;
}

Fixed::Fixed(const Fixed& F){
    (void)F;
    std::cout<<"Copy constructor called"<<std::endl;
}

Fixed&  Fixed::operator= (Fixed& a){
    std::cout<<"Copy assignment operator called"<<std::endl;
    this->nbr = a.nbr;
    // this->fractional = a.fractional;
    return *this;
}

Fixed::~Fixed()
{
    std::cout<<"Destructor called"<<std::endl;
}

int Fixed::getRawBits(void){
    std::cout<<"getRawBits member function called"<<std::endl;
    return(nbr);
}

void Fixed::setRawBits( int const raw ){
    std::cout<<"getRawBits member function called"<<std::endl;
    this->nbr = raw;
}
