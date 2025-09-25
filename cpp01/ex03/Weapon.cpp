#include "Weapon.hpp"

Weapon::Weapon(const std::string &type) : _type(type) {}

void  Weapon::setType(const std::string &new_type)
{
    _type = new_type;
}

const std::string &Weapon::getType()
{
    return _type;
}