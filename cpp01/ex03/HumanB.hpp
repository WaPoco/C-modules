#pragma once
#include "Weapon.hpp"

class HumanB
{
    public:
        HumanB(const std::string &name);
        void    attack();
        void setWeapon(Weapon &weapon);
    private:
        Weapon *_weaponB;
        std::string _name;
};