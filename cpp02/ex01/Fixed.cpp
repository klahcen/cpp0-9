
#include "Fixed.hpp"

Fixed::Fixed(){

    std::cout<<"Default constructor called"<<std::endl;
    this->value =0;
}

Fixed::Fixed(const Fixed& F){
    std::cout<<"Copy constructor called"<<std::endl;
    this->value = F.value;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout<<"Copy assignment operator called"<<std::endl;
    this->value = other.value;
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

Fixed::Fixed(const int value){
    this->value = value;
}

Fixed::Fixed(const float value){
        this->value = value;
}

float Fixed::toFloat( void ) const{
    std::cout<<"Float constructor called"<<std::endl;
    return (roundf(this->value)*(1 << 8));
}

int Fixed::toInt( void ) const{
    std::cout<<"int constructor called"<<std::endl;
    return (this->value);
}
std::ostream& operator<<(std::ostream& oc, const Fixed& obj){
    oc << obj.getRawBits();
    return (oc);
}
