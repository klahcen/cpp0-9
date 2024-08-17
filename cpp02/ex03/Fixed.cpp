
#include "Fixed.hpp"

Fixed::Fixed(){

    this->value =0;
}

Fixed::Fixed(const int intvalue){
    this->value = intvalue << fractional;
}

Fixed::Fixed(const float floatvalue){
        this->value = (roundf(floatvalue * (1 << fractional)));
}

Fixed::Fixed(const Fixed& F){
    this->value = F.value;
}


Fixed& Fixed::operator=(const Fixed& other) {
    if(this  != &other)
        this->value = other.value;
    return *this;
}

bool Fixed::operator< (const Fixed& other){
    return (this->value < other.value);
}

bool Fixed::operator<= (const Fixed& other){
    return (this->value <= other.value);
}

bool Fixed::operator> (const Fixed& other){
    return (this->value > other.value);
}

bool Fixed::operator>= (const Fixed& other){
    return (this->value >= other.value);
}

bool Fixed::operator== (const Fixed& other){
    return (this->value == other.value);
}

bool Fixed::operator!= (const Fixed& other){
    return (this->value != other.value);
}

Fixed Fixed::operator+ (const Fixed& other){
    Fixed r;
    r.value =(this->value + other.value)>> fractional;
    return r;
}

Fixed Fixed::operator- (const Fixed& other){
    Fixed r;
    r.value =(this->value - other.value)>> fractional;
    return r;
}

Fixed Fixed::operator* (const Fixed& other){
    Fixed r;
    r.value =(this->value * other.value)>> fractional;
    return r;
}

Fixed Fixed::operator/ (const Fixed& other){
   Fixed r;
    r.value =(this->value / other.value)>> fractional;
    return r;
}

Fixed& Fixed::operator++() {
    value++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    ++value;
    return temp;
}
Fixed& Fixed::operator--() {
    value--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    --value;
    return temp;
}

Fixed::~Fixed()
{
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

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
        return (a.value > b.value) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
        return (a.value < b.value) ? a : b;
}

