#include "Fixed.hpp"

class Point
{
    private:
        const Fixed x;
        const Fixed y;
    public:
        Point(): x(0), y(0) {};
        Point(const float a, const float b) : x(a), y(b) {};
        Point(const Point& other) {};

};