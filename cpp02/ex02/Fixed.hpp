#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int _value;
        static const int _fractional_bits = 8;
    public:
        Fixed();
        int getRawBits(void) const;
        void setRawBits(int const raw);
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        Fixed(const int number);
        Fixed(const float number);
        // comparison operators
        bool operator==(const Fixed& other) const;
        bool operator>(const Fixed& other) const;
        bool operator<(const Fixed& other) const;
        bool operator<=(const Fixed& other) const;
        bool operator>=(const Fixed& other) const;
        bool operator!=(const Fixed& other) const;
        // arithmetic operators
        Fixed operator+(const Fixed& other) const;
        Fixed operator-(const Fixed& other) const;
        Fixed operator*(const Fixed& other) const;
        Fixed operator/(const Fixed& other) const;
        // increment/decrement
        Fixed operator++(int);
        Fixed& operator++();
        Fixed operator--(int);
        Fixed& operator--();
        // min, max
        static Fixed min(Fixed &numb1, Fixed &numb2);
        static Fixed min(const Fixed &numb1, const Fixed &numb2);
        static Fixed max(Fixed &numb1, Fixed &numb2);
        static Fixed max(const Fixed &numb1, const Fixed &numb2);
        int toInt( void ) const;
        float toFloat( void ) const;
        ~Fixed();
};

std::ostream& operator<<(std::ostream& os, const Fixed& a);
