#include "Cat.hpp"

Cat::Cat(): Animal("Cat")
{
    this->brain = new Brain();
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
    std::cout << "Cat copy assigment" << std::endl;
    this->brain = new Brain(*other.brain);
}

Cat Cat::operator=(const Cat &other)
{
    if (this!= &other)
    {
        delete this->brain;
        this->brain = new Brain(*other.brain);
    }
    return *this;
}

Brain *Cat::getBrain()
{
    return this->brain;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
    delete this->brain;
}

void Cat::makesound()
{
    std::cout << "Miaou" << std::endl;
}
