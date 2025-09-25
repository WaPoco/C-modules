#include "HumanA.hpp"

void    HumanA::attack()
{
    std::cout << _name << " attacks with their " << _weaponA.getType() << std::endl;
}

HumanA::HumanA(const std::string &name, Weapon &weapon) : _name(name) , _weaponA(weapon) {}
