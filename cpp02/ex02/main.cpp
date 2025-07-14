
#include "Fixed.hpp"

int main( void ) {
Fixed a;
Fixed d(0.009f);
Fixed c(1);
Fixed const b( Fixed( 5.5f ) / Fixed( 0.009f) );
std::cout << d << std::endl;
 std::cout << ++a << std::endl;
 std::cout << a << std::endl;
 std::cout << a++ << std::endl;
 std::cout << a << std::endl;
 std::cout << b << std::endl;
 std::cout << Fixed::max( a, b ) << std::endl;
return 0;
}
