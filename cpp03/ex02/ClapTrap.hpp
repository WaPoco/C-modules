#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP
# include <iostream>

class ClapTrap
{
    protected:
        std::string _name;
        int _hit_points;
        int _energy_points;
        int _attack_damage;
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap& operator=(const ClapTrap& other);
        ClapTrap(const ClapTrap&);
        ~ClapTrap();
        // setter
        void set_hit_points(int hit_points);
        void set_energy_points(int energy_points);
        virtual void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};
#endif