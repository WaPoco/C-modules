#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain default constructor" << std::endl;
}

Brain::Brain(const Brain &other)
{
    for (int i = 0; i < 100; i++)
        this->ideas[i] = other.ideas[i];
}

Brain& Brain::operator=(const Brain &other)
{
    for (int i = 0; i < 100; i++)
        this->ideas[i] = other.ideas[i];
    return *this;
}

void Brain::setIdea(int index, const std::string idea)
{
    if (0 <= index && index <= 100)
        ideas[index] = idea;
}

std::string Brain::getIdea(int index)
{
    if (0 <= index && index <= sizeof(ideas) / sizeof(std::string))
        return ideas[index];
    return "";
}

Brain::~Brain()
{
    std::cout << "Brain destructor" << std::endl;
}