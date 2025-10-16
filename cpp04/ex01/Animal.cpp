#include "Animal.hpp"

Animal::Animal() : _type("")
{
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const std::string type) : _type(type)
{
    std::cout << "Animal constructor called" << std::endl;
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
    std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType()
{
    return (this->_type);
}

void Animal::makesound()
{
}