#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
}

WrongCat WrongCat::operator=(const WrongCat &other)
{
    if (this!= &other)
        this->_type = other._type;
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor destroyed!" << std::endl;
}

void WrongCat::makesound()
{
    std::cout << "Miaou" << std::endl;
}