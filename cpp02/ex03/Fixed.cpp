#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
    //std::cout << "Default constructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    //std::cout << "getRawBits member function called" << std::endl;
    return (_value);
}

void Fixed::setRawBits(int const raw)
{
    _value = raw;
}
Fixed& Fixed::operator=(const Fixed& other)
{
    //std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        _value = other.getRawBits();
    return (*this);
}

Fixed::~Fixed()
{
    //std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
    //std::cout << "Copy constructor called" << std::endl;
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

bool Fixed::operator==(const Fixed &other) const
{
    return (this->_value == other._value);
}

bool Fixed::operator>(const Fixed &other) const
{
    return (this->_value > other._value);
}

bool Fixed::operator<(const Fixed &other) const
{
    return (this->_value < other._value);
}

bool Fixed::operator<=(const Fixed &other) const
{
    return (this->_value <= other._value);
}

bool Fixed::operator>=(const Fixed &other) const
{
    return (this->_value >= other._value);
}

bool Fixed::operator!=(const Fixed &other) const
{
    return (this->_value != other._value);
}

Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed result;

    result._value = other._value +_value;
    return (result);
}

Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed result;

    result._value = _value - other._value;
    return (result);
}

Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed result;

    result._value = other._value * _value / (1 << _fractional_bits);
    return (result);
}

Fixed Fixed::operator/(const Fixed &other) const
{
    Fixed result;

    result._value = _value * (1 << _fractional_bits) / other._value;
    return (result);    
}

// post-increment
Fixed Fixed::operator++(int)
{
    Fixed tmp = *this;
    _value++;
    return (tmp);
}

Fixed &Fixed::operator++()
{
    _value++;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed tmp = *this;
    _value--;
    return (tmp);
}

Fixed &Fixed::operator--()
{
    _value--;
    return (*this);
}

Fixed Fixed::min(Fixed &numb1, Fixed &numb2)
{
    Fixed   min;

    min = numb2;
    if (numb1._value <= numb2._value)
        min = numb1;
    return (min);
}

Fixed Fixed::min(const Fixed &numb1, const Fixed &numb2)
{
    Fixed   min;

    min = numb2;
    if (numb1._value <= numb2._value)
        min = numb1;
    return (min);
}

Fixed Fixed::max(Fixed &numb1, Fixed &numb2)
{
    Fixed   max;

    if (numb1._value >= numb2._value)
        max = numb1;
    else
        max = numb2;
    return (max);
}

Fixed Fixed::max(const Fixed &numb1, const Fixed &numb2)
{
    Fixed   max;

    max = numb2;
    if (numb1._value >= numb2._value)
        max = numb1;
    return (max);

}
