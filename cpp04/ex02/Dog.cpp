#include "Dog.hpp"

Dog::Dog(): AAnimal("Dog")
{
    this->brain = new Brain();
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : AAnimal(other)
{
    std::cout << "Dog copy assigment" << std::endl;
    this->brain = new Brain(*other.brain);
}

Dog& Dog::operator=(const Dog &other)
{
    if (this!= &other)
    {
        delete this->brain;
        this->brain = new Brain(*other.brain);
    }
    return *this;
}

Brain *Dog::getBrain() const
{
    return this->brain;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
    delete this->brain;
}

void Dog::makesound() const
{
    std::cout << "Wuff" << std::endl;
}
