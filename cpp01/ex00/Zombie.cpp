#include "Zombie.hpp"

Zombie::~Zombie()
{
    std::cout << _name << std::endl;
}

Zombie::Zombie(std::string name)
{
    _name = name;
    announce();
};

void    Zombie::announce()
{
    std::cout << _name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}
