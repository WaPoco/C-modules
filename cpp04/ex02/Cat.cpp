#include "Cat.hpp"

Cat::Cat(): AAnimal("Cat")
{
    this->brain = new Brain();
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : AAnimal(other)
{
    std::cout << "Cat copy assigment" << std::endl;
    this->brain = new Brain(*other.brain);
}

Cat& Cat::operator=(const Cat &other)
{
    if (this!= &other)
    {
        delete this->brain;
        this->brain = new Brain(*other.brain);
    }
    return *this;
}

Brain *Cat::getBrain() const
{
    return this->brain;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
    delete this->brain;
}

void Cat::makesound() const
{
    std::cout << "Miaou" << std::endl;
}
