#include <iostream>

class ClapTrap
{
    private:
        std::string _name;
        int _hit_points;
        int _energy_points;
        int _attack_damage;
    public:
        ClapTrap(std::string name): _name(name) {};
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
};