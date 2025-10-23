#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (_value);
}

void Fixed::setRawBits(int const raw)
{
    _value = raw;
}
Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        _value = other.getRawBits();
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    _value = other.getRawBits();
}

Fixed::Fixed(const int number)
{
    _value = number << _fractional_bits;
}

Fixed::Fixed(const float number)
{
    _value = roundf(number * (1 << _fractional_bits));   
}

std::ostream &operator<<(std::ostream &os, const Fixed& a)
{
    os << a.toFloat();
    return (os);
}

int Fixed::toInt(void) const
{
    return (_value >> _fractional_bits);
}

float Fixed::toFloat(void) const
{
    return ((float)_value / (1 << _fractional_bits));
}
