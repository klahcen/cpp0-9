
#ifndef FIXED_HPP
# define FINED_HPP

class Fixed{
    private:
        int nbr;
        static const int fractional;
    public:
        Fixed();
        Fixed(const Fixed& F);
        Fixed& operator=(Fixed&);
        ~Fixed();
}

#endif