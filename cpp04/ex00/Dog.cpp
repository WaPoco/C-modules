#include "Dog.hpp"

Dog::Dog(): Animal("Dog")
{
    std::cout << _type << " default constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
    std::cout << _type << " constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog &other)
{
    if (this != &other)
        this->_type = other._type;
    std::cout << _type << " copy constructor called" << std::endl;
    return *this;
}

Dog::~Dog()
{
    std::cout << _type << " destructor called!" << std::endl;
}

void Dog::makesound()
{
    std::cout << "Wuff" << std::endl;
}