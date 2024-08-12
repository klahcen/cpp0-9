
#ifndef FIXED_HPP
# define FINED_HPP

#include <iostream>

class Fixed{
    private:
        int nbr;
        static const int fractional;
    public:
        Fixed();
        Fixed(const Fixed& F);
        Fixed& operator= (Fixed& a);
        ~Fixed();
        int getRawBits(void);
        void setRawBits( int const raw );
};

#endif