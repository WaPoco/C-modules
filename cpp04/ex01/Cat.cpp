#include "Cat.hpp"

Cat::Cat(): Animal("Cat")
{
    this->brain = new Brain();
    std::cout << _type << " default constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
    this->brain = new Brain(*other.brain);
    std::cout << _type << " constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat &other)
{
    if (this!= &other)
    {
        delete this->brain;
        this->brain = new Brain(*other.brain);
    }
    std::cout << _type << " copy constructor called" << std::endl;
    return *this;
}

Brain *Cat::getBrain() const
{
    return this->brain;
}

Cat::~Cat()
{
    delete this->brain;
    std::cout << _type << " destructor called!" << std::endl;
}

void Cat::makesound()
{
    std::cout << "Miaou" << std::endl;
}
