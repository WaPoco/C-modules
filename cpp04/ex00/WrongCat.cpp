#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
    std::cout << _type << " default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
    std::cout << _type << " constructor called" << std::endl;
}

WrongCat WrongCat::operator=(const WrongCat &other)
{
    if (this!= &other)
        this->_type = other._type;
    std::cout << _type << " copy constructor called" << std::endl;
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << _type << " destructor called!" << std::endl;
}

void WrongCat::makesound()
{
    std::cout << "Miaou" << std::endl;
}