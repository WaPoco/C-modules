#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("")
{
}

WrongAnimal::WrongAnimal(const std::string type) : _type(type)
{
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
    if (&other != this)
        this->_type = other._type;
}

WrongAnimal WrongAnimal::operator=(const WrongAnimal &other)
{
    if (&other != this)
        this->_type = other._type;
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor destroyed!";
}

std::string WrongAnimal::getType()
{
    return (this->_type);
}

void WrongAnimal::makesound()
{
}