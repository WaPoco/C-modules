#include "Zombie.hpp"

Zombie::~Zombie()
{
    std::cout << "Destructor of " << _name << " was called" << std::endl;
}

Zombie::Zombie(const std::string& name)
{
    _name = name;
};

void    Zombie::announce() const
{
    std::cout << _name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}
