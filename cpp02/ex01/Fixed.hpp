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
        int toInt( void ) const;
        float toFloat( void ) const;
        ~Fixed();
};