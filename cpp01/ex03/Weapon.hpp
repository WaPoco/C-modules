#ifndef WEAPON_HPP
#define WEAPON_HPP
# include <iostream>

class Weapon
{
    private:
        std::string _type;
    public:
        const std::string &getType();
        void  setType(const std::string &new_type);
        Weapon(const std::string &type);
};

#endif