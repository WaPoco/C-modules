#include "Dog.hpp"

Dog::Dog(): Animal("Dog")
{
}

Dog::Dog(const Dog &other) : Animal(other)
{
}

Dog Dog::operator=(const Dog &other)
{
    if (this != &other)
        this->_type = other._type;
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destructor destroyed!" << std::endl;
}

void Dog::makesound()
{
    std::cout << "Wuff" << std::endl;
}