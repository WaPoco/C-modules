#pragma once
#include "Weapon.hpp"

class HumanA
{
    public:
        HumanA();
        HumanA(std::string, Weapon);
        void    attack();
    private:
        Weapon _weaponA;
        std::string& _name;
};