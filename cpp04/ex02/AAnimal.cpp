#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("Animal")
{
    std::cout << "Animal default constructor called" << std::endl;
}

AAnimal::AAnimal(const std::string type) : _type(type)
{
    std::cout << "Animal constructor called" << std::endl;
}

AAnimal::~AAnimal()
{
    std::cout << "Animal destructor called" << std::endl;
}

std::string AAnimal::getType() const
{
    return (this->_type);
}
