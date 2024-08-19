
#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed{
    private:
        int value;
        static const int fractional=8;
    public:
        Fixed();
        Fixed(const Fixed& F);
        Fixed& operator= (const Fixed& a);
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits( int const raw );
};

#endif