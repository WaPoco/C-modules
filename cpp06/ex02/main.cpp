#include "identify.hpp"
#include <iostream>

int main()
{
    Base* obj = generate();

    std::cout << "Pointer: ";
    identify(obj);

    std::cout << "Reference: ";
    identify(*obj);

    delete obj;
    return 0;
}
