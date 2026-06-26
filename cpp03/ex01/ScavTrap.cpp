#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "ScavTrap constructor " << _name << " called" << std::endl;
}

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "ScavTrap default constructor " << _name << " called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << "ScavTrap copy contructor " << _name << " called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other)
{
    if (this != &other)
        ClapTrap::operator=(other);
    std::cout << "ScavTrap copy assignment contructor " << _name << " callled" << std::endl;
    return *this;
}

void ScavTrap::attack(const std::string &target)
{
    if (_energy_points > 0 && _hit_points > 0)
    {
        std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage!" << std::endl;
        _energy_points--;
    }
    else
        std::cout << "ScavTrap " << _name << " cannot attack (no energy or dead)\n";
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor " << _name << " called" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode" << std::endl;
}
