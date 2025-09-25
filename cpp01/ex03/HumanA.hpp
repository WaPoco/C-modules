#pragma once
#include "Weapon.hpp"

class HumanA
{
    private:
        Weapon& _weaponA;
        std::string _name;
    public:
        HumanA(const std::string &name, Weapon &weapon);
        void    attack();
};