
#ifndef FIXED_HPP
# define FINED_HPP

#include <iostream>
#include <cmath>

class Fixed{
    private:
        int value;
        static const int fractional=8;
    public:
        Fixed();
        Fixed(const int intvalue);
        Fixed(const float floatvalue);
        Fixed(const Fixed& F);
        Fixed& operator=(const Fixed& other);
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& oc, const Fixed& obj);

#endif