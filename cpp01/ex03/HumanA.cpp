#include "HumanA.hpp"

void    HumanA::attack() const
{
    std::cout << _name << " attacks with their " << _weaponA.getType() << std::endl;
}

HumanA::HumanA(const std::string &name, Weapon &weapon) : _weaponA(weapon) ,_name(name)  {}
