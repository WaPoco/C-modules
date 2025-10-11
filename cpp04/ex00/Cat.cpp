#include "Cat.hpp"

Cat::Cat(): Animal("Cat")
{
}

Cat::Cat(const Cat &other) : Animal(other)
{
}

Cat Cat::operator=(const Cat &other)
{
    if (this!= &other)
        this->_type = other._type;
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destructor destroyed!" << std::endl;
}

void Cat::makesound()
{
    std::cout << "Miaou" << std::endl;
}