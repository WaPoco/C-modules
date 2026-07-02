#include <iostream>
#include "Array.hpp"

int main()
{
    Array<std::string> a(5);
    a[0] = "1";
    a[1] = "2";

    Array<std::string> b(a);
    std::cout << &a << std::endl << &b << std::endl;
    Array<std::string> c(1);
    c = a;
    std::cout << &a << std::endl << &c;
    std::cout << c[0] << " " << c[5] << std::endl;
    return (1);
}