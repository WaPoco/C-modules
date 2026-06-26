#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const std::string type) : _type(type)
{
    std::cout << "Animal constructor of type " << _type << " called" << std::endl;
}

Animal::Animal(const Animal &other)
{
    if (&other != this)
        this->_type = other._type;
    std::cout << _type << " copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal &other)
{
    if (&other != this)
        this->_type = other._type;
    std::cout << _type << " copy  assignment constructor called" << std::endl;
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal destructor of type " << _type << " called!" << std::endl;
}

std::string Animal::getType()
{
    return (this->_type);
}

void Animal::makesound()
{
    std::cout << "..." << std::endl;
}