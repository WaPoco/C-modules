#ifndef HUMANA_HPP
#define HUMANA_HPP
# include "Weapon.hpp"

class HumanA
{
    private:
        Weapon& _weaponA;
        std::string _name;
    public:
        HumanA(const std::string& name, Weapon& weapon);
        void    attack() const;
};

#endif