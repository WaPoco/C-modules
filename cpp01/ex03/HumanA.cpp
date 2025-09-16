#include "HumanA.hpp"

void    HumanA::attack()
{
    std::cout << _name << " attacks with their " << _weaponA.getType() << std::endl;
}

HumanA::HumanA(std::string &name, Weapon weapon) : name(_name) , weapon(_weaponA) {}
