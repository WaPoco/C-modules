#include <iostream>

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
        ~Fixed();
};