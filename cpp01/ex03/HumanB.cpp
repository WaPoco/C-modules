#include "HumanB.hpp"

HumanB::HumanB(const std::string &name) : _weaponB(NULL), _name(name) {}

void    HumanB::attack() const
{
    if (_weaponB)
        std::cout << _name << " attacks with their " << (*_weaponB).getType() << std::endl;
    else
        std::cout << _name << " attacks with no weapon " << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
    _weaponB = &weapon;
}
