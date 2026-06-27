#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "FragTrap default constructor " << _name << " called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{   
    std::cout << "FragTrap constructor " << _name << " called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    std::cout << "FragTrap copy contructor " << _name << " callled" << std::endl;
}

FragTrap FragTrap::operator=(const FragTrap &other)
{
    if (this != &other)
        ClapTrap::operator=(other);
    std::cout << "FragTrap asignment operator " << _name << " called" << std::endl;
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap desctrutor " << _name << " called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << _name << " high Five Guy" << std::endl;
}

void FragTrap::attack(const std::string &target)
{
    if (_energy_points > 0 && _hit_points > 0)
    {
        std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage!" << std::endl;
        _energy_points--;
    }
    else
        std::cout << "FragTrap " << _name << " cannot attack (no energy or dead)\n";
}
