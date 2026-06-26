#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("Default"),_hit_points(10), _energy_points(10), _attack_damage(0)
{
    std::cout << "ClapTrap " << _name << " created (default)\n";
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
    std::cout << "ClapTrap " << _name << " created\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
    if (this != &other)
    {
        this->_name = other._name;
        this->_energy_points = other._energy_points;
        this->_hit_points = other._hit_points;
        this->_attack_damage= other._attack_damage;
    }
    std::cout << "ClapTap assignment operator called" << std::endl;
    return (*this);
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    this->_name = other._name;
    this->_energy_points = other._energy_points;
    this->_hit_points = other._hit_points;
    this->_attack_damage= other._attack_damage;
    std::cout << "ClapTrap(copy constructor) " << _name << " copied\n";
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << _name << " destroyed\n";
}

void ClapTrap::set_hit_points(int hit_points)
{
    this->_hit_points = hit_points;
}

void ClapTrap::set_energy_points(int energy_points)
{
    this->_energy_points = energy_points;
}

void ClapTrap::attack(const std::string &target)
{
    if (_energy_points > 0 && _hit_points > 0)
    {
        std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage!" << std::endl;
        _energy_points--;
    }
    else
        std::cout << "ClapTrap " << _name << " cannot attack (no energy or dead)\n";

}

void ClapTrap::takeDamage(unsigned int amount)
{
    _hit_points -= amount;
    if (_hit_points < 0)
        _hit_points = 0;
    std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage! Remaning HP: " << _hit_points << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_energy_points > 0 && _hit_points > 0)
    {
        _hit_points += amount;
        _energy_points--;
        std::cout << "ClapTrap " << _name << " repairs itself for " << amount << " hit points! Current HP: " << _hit_points << std::endl;
        return ;
    }
    else
        std::cout << "ClapTrap " << _name << " cannot repair\n";
}
