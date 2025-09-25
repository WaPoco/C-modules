#include "Zombie.hpp"

Zombie::Zombie()
{
}

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
Zombie  *Zombie::newZombie(std::string name)
{
    Zombie *newZombie = new Zombie(name);
    return (newZombie);
}
void    Zombie::randomChump(std::string name)
{
    Zombie randomZombie (name);
}