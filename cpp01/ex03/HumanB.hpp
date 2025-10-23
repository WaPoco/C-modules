#ifndef HUMANB_HPP
#define HUMANB_HPP
# include "Weapon.hpp"

class HumanB
{
    public:
        HumanB(const std::string &name);
        void    attack() const;
        void setWeapon(Weapon &weapon);
    private:
        Weapon *_weaponB;
        std::string _name;
};

#endif