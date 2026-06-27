#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("Wromg Animal")
{
    std::cout << "Wrong Animal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string type) : _type(type)
{
    std::cout << "Wrong Animal constructor of type " << _type << " called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
    if (&other != this)
        this->_type = other._type;
    std::cout << _type << " copy constructor called" << std::endl;
}

WrongAnimal WrongAnimal::operator=(const WrongAnimal &other)
{
    if (&other != this)
        this->_type = other._type;
    std::cout << _type << " copy  assignment constructor called" << std::endl;
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "Wrong Animal destructor of type " << _type << " called!" << std::endl;
}

std::string WrongAnimal::getType()
{
    return (this->_type);
}

void WrongAnimal::makesound()
{
    std::cout << "Wrong Animal sound ..." << std::endl;
}