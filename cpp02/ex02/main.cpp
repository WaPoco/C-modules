#include <iostream>
#include "Fixed.hpp"
#include <iostream>

int main( void ) 
{
    Fixed   a;
    Fixed const b( Fixed(-5.05f) * Fixed(-0.1f) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::min( a, b ) << std::endl;
    return 0;
}