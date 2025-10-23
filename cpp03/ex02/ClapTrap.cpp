#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _hit_points(0), _energy_points(10), _attack_damage(0)
{
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(1)
{
    std::cout << "ClapTrap Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name, int hit_points, int energy_points, int attack_damage) :_name(name), _hit_points(hit_points), _energy_points(energy_points), _attack_damage(attack_damage)
{
}

ClapTrap ClapTrap::operator=(const ClapTrap &other)
{
    if (this != &other)
    {
        this->_name = other._name;
        this->_energy_points = other._energy_points;
        this->_hit_points = other._hit_points;
        this->_attack_damage= other._attack_damage;
    }
    std::cout << "ClapTrap asignment operator called" << std::endl;
    return (*this);
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    this->_name = other._name;
    this->_energy_points = other._energy_points;
    this->_hit_points = other._hit_points;
    this->_attack_damage= other._attack_damage;
    std::cout << "ClapTrap copy (shallow) contructor callled" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor has been called" << std::endl;
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
    set_energy_points(_energy_points - 1);
    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hit_points - amount >= 0)
    {
        set_hit_points(_hit_points - amount);
        std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage! Remaning HP: " << _hit_points << std::endl;
        return ;
    }
    std::cout << "Not enough HP: " << std::endl;
}


void ClapTrap::beRepaired(unsigned int amount)
{
    if(_energy_points - 1 >= 0)
    {
        set_hit_points(_hit_points + amount);
        set_energy_points(_energy_points - 1);
        std::cout << "ClapTrap " << _name << " repairs itself for " << amount << " hit points! Current HP: " << _hit_points << std::endl;
        return ;
    }
    std::cout << "Not enough EP: " << std::endl;
}
