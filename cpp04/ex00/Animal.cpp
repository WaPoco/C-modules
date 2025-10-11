#include "Animal.hpp"

Animal::Animal() : _type("")
{
}

Animal::Animal(const std::string type) : _type(type)
{
}

Animal::Animal(const Animal &other)
{
    if (&other != this)
        this->_type = other._type;
}

Animal Animal::operator=(const Animal &other)
{
    if (&other != this)
        this->_type = other._type;
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal destructor destroyed!";
}

std::string Animal::getType()
{
    return (this->_type);
}

void Animal::makesound()
{
}