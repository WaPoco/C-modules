#include "Cat.hpp"

Cat::Cat(): Animal("Cat")
{
    std::cout << _type << " default constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
    std::cout << _type << " constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat &other)
{
    if (this!= &other)
        this->_type = other._type;
    return *this;
    std::cout << _type << " copy constructor called" << std::endl;
}

Cat::~Cat()
{
    std::cout << _type << " destructor called!" << std::endl;
}

void Cat::makesound()
{
    std::cout << "Miaou" << std::endl;
}

