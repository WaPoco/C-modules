#pragma once
#include "Weapon.hpp"

class HumanB
{
    public:
        HumanB(std::string &name);
        void    attack();
    private:
        Weapon _weaponB;
        std::string _name;
};