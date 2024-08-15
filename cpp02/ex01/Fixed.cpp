
#include "Fixed.hpp"

Fixed::Fixed(){

    std::cout<<"Default constructor called"<<std::endl;
    this->value =0;
}

Fixed::Fixed(const int intvalue){
    std::cout << "Int constructor called" << std::endl;
    this->value = intvalue << fractional;
}

Fixed::Fixed(const float floatvalue){
        std::cout << "Float constructor called" << std::endl;
        this->value = (roundf(floatvalue * (1 << fractional)));
}

Fixed::Fixed(const Fixed& F){
    std::cout<<"Copy constructor called"<<std::endl;
    this->value = F.value;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout<<"Copy assignment operator called"<<std::endl;
    if(this  != &other)
        this->value = other.value;
    return *this;
}

Fixed::~Fixed()
{
    std::cout<<"Destructor called"<<std::endl;
}

int Fixed::getRawBits(void) const{
    return(value);
}

void Fixed::setRawBits( int const raw ){
    this->value = raw;
}

float Fixed::toFloat( void ) const{
    return static_cast<float>(this->value) / (1 << fractional);
}

int Fixed::toInt( void ) const{
    return (this->value>>fractional);
}
std::ostream& operator<<(std::ostream& oc, const Fixed& obj){
    oc << obj.toFloat();
    return (oc);
}



