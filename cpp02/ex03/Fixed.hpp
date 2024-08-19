
#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{
    private:
        int value;
        static const int fractional=9;
    public:
        Fixed();
        Fixed(const int intvalue);
        Fixed(const float floatvalue);
        Fixed(const Fixed& F);
        Fixed&  operator=  (const Fixed& other);
        bool    operator<  (const Fixed& other);
        bool    operator<= (const Fixed& other);
        bool    operator>  (const Fixed& other);
        bool    operator>= (const Fixed& other);
        bool    operator== (const Fixed& other);
        bool    operator!= (const Fixed& other);
        Fixed   operator+  (const Fixed& other);
        Fixed     operator-  (const Fixed& other);
        Fixed   operator*  (const Fixed& other);
        Fixed   operator/  (const Fixed& other);
        Fixed&  operator++ ();
        Fixed   operator++ (int);
        Fixed&  operator-- ();
        Fixed   operator-- (int);
        ~Fixed();
        int     getRawBits (void) const;
        void    setRawBits (int const raw);
        float   toFloat    (void) const;
        int     toInt      (void) const;
        static const Fixed& max(const Fixed& a, const Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& oc, const Fixed& obj);

#endif