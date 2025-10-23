#include "Dog.hpp"

Dog::Dog(): Animal("Dog")
{
    this->brain = new Brain();
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
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

Brain *Dog::getBrain()
{
    return this->brain;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
    delete this->brain;
}

void Dog::makesound()
{
    std::cout << "Wuff" << std::endl;
}
