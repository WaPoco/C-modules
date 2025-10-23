#include "Zombie.hpp"

Zombie::Zombie()
{
}

void Zombie::setName(const std::string &name)
{
    _name = name;
}

Zombie::~Zombie()
{
    std::cout << "Destructor of " << _name << " called" << std::endl;
}

Zombie::Zombie(const std::string& name)
{
    _name = name;
}

void    Zombie::announce() const
{
    std::cout << _name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie  *newZombie(const std::string& name)
{
    Zombie *newZombie = new Zombie(name);
    return (newZombie);
}

void    randomChump(const std::string& name)
{
    Zombie randomZombie (name);
    randomZombie.announce();
}