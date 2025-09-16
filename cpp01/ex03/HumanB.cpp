#include "HumanB.hpp"

void    HumanB::attack()
{
    std::cout << _name << " attacks with their " << _weaponB.getType() << std::endl;
}

HumanB::HumanB(std::string &name) : _name(name) {}